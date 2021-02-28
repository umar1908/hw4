#include <iostream>
#include <iomanip>
using namespace std;


// #include <functional>
#include <algorithm>
// #include <vector>
// #include <string>
// #include <cmath>
// #include <cstdlib>
// #include<utility>
// #include <exception>
// #include <bitset>
#include<random>
#include <iterator>
#include <numeric>
bool is_simple(const int&);
int square(const int& elem);


int main(){
  system("chcp 1251"); //��� ����������� ����������� ��������

  srand(time(0));
  mt19937 g(rand());
  uniform_int_distribution<int> distr(0,100);




  vector<int> seq1{1,2,3,4,5,6,7,8,9,10};
  cout<<"�������� ������������������\n";
  ostream_iterator<int> cout_it(cout," ");
  copy(seq1.cbegin(),seq1.cend(),cout_it);

  cout<<"\n������� ��������� ��������� ��� ���������� � �����. ��� ��������� ����� ������� Ctrl+Z\n";
  istream_iterator<int> cin_it (cin);
  istream_iterator<int> eos;
  copy(cin_it, eos, back_inserter(seq1));
  copy(seq1.cbegin(),seq1.cend(),cout_it);


  cout<<"\n������������ ������\n";
  shuffle(seq1.begin(),seq1.end(),g);
  copy(seq1.cbegin(),seq1.cend(),cout_it);

  cout<<"\n���������� ���������:\n";
  auto new_end=unique(seq1.begin(),seq1.end());
  seq1.erase(new_end,seq1.end());
  copy(seq1.cbegin(),seq1.cend(),cout_it);


  cout<<endl<<"�������� ���������:"<<count_if(seq1.cbegin(),seq1.cend(), [](auto elem)->bool{return elem%2!=0;})<<endl;

  cout<<"����������� �������:"<<*min_element(seq1.cbegin(),seq1.cend())<<"\n������������ �������"<<
  *max_element(seq1.cbegin(),seq1.cend())<<endl;

  auto simple=find_if(seq1.begin(),seq1.end(),is_simple);
  if(simple==seq1.end()){
    cout<<"������� ����� ���\n";
  }
  else{
    cout<<"������ ������� �������:"<<*simple<<endl;
  }
  cout<<"������ ��������� �� ����������\n";
  transform(seq1.begin(),seq1.end(),seq1.begin(),square);
  copy(seq1.cbegin(),seq1.cend(),cout_it);
  cout<<endl;

  vector<int> seq2(size(seq1));

  cout<<"������������������ 2\n";
  generate(seq2.begin(),seq2.end(),[&distr,&g]()->int{return distr(g);});
  copy(seq2.cbegin(),seq2.cend(),cout_it);

  cout<<"\n����� ���������:";
  cout<<accumulate(seq2.cbegin(),seq2.cend(),0,[](const auto& lhs,const auto& rhs){return lhs+rhs;})<<endl;

  cout<<"������� ������ 3 ��������� �� 1\n";
  fill(seq2.begin(),seq2.begin()+3,1);
  copy(seq2.cbegin(),seq2.cend(),cout_it);
  cout<<endl;

  cout<<"�3=�1-�2:\n";
  vector<int> seq3(size(seq2));
  generate(seq3.rbegin(),seq3.rend(),[&seq1,&seq2]()->int{
    static auto seq2c=seq2;
    static auto seq1c=seq1;
    int curr=seq1c.back()-seq2c.back();
    seq1c.pop_back();
    seq2c.pop_back();
    return curr;});
  copy(seq3.cbegin(),seq3.cend(),cout_it);


  cout<<endl<<"������� ��� �������� <0 �� 0\n";
  replace_if(seq3.begin(),seq3.end(),[](const int& elem)->bool{return elem<0;},0);
  copy(seq3.cbegin(),seq3.cend(),cout_it);


  cout<<endl<<"������ ��� ������� ��������\n";
  auto new_end3=remove(seq3.begin(),seq3.end(),0);
  seq3.erase(new_end3,seq3.end());
  copy(seq3.cbegin(),seq3.cend(),cout_it);


  cout<<endl<<"��������� �3\n";
  reverse(seq3.begin(),seq3.end());
  copy(seq3.cbegin(),seq3.cend(),cout_it);

  cout<<"\n��� 3 ��������:";
  sort(seq3.begin(),seq3.end());
  auto iter=seq3.rbegin();
  copy(iter,iter+3,cout_it);

  cout<<"\n��������� �1 � �2\n";
  sort(seq1.begin(),seq1.end());
  sort(seq2.begin(),seq2.end());
  copy(seq1.cbegin(),seq1.cend(),cout_it);
  cout<<endl;
  copy(seq2.cbegin(),seq2.cend(),cout_it);

  cout<<"\n ������� �1 � �2:\n";
  vector<int>seq4;
  merge(seq1.cbegin(),seq1.cend(),seq2.cbegin(),seq2.cend(),back_inserter(seq4));
  copy(seq4.cbegin(),seq4.cend(),cout_it);
  cout<<endl;

  cout<<"������ �������� ��� ������������� ������� 1\n";
  cout<<"����� "<<*lower_bound(seq4.begin(),seq4.end(),1)<<" � "<<*upper_bound(seq4.begin(),seq4.end(),1);


}


bool is_simple(const int& elem){
  int buffer{2};
  if (elem==1){
    return true;
  }
  while (buffer<elem/2){
    if(elem%buffer==0){
      return false;
    }
    buffer++;
  }
  return true;
}

int square(const int& elem){
  return elem*elem;
}
