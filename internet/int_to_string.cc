#include <vector>
#include <iostream>

using namespace std;
int main(){
  vector<int> a;
  cout << a.capacity();//  0
  a.push_back(1);
  cout << a.capacity();//  1
  vector<int>::iterator it1 = a.begin();
  cout << "begin" <<  *it1<< endl;
  a.push_back(2);
  cout << "begin" <<  *it1<< endl;
  cout << a.capacity();//  2
  vector<int>::iterator it2 = a.begin();
  cout << "begin" <<  *it2<< endl;
  a.push_back(4);
  cout << a.capacity();//  4
  cout << "begin" <<  *it2<< endl;

}



