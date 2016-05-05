#include <set>
#include <sstream>
#include <iostream>

using namespace std;


void count(string w1, string w2, std::set<string>& s1, std::set<string>& s2, int& result){
	if (s1.find(w1) != s1.end() && s2.find(w2) !=s2.end()) {
		result++;
	} else {
		s1.insert(w1);
		s2.insert(w2);
	}
}
int main(){
	int T;
  	cin >> T;
  	int i = 0;
	while (i<T)	{
		int N = 0;
		cin >> N;
		int j = 0;
		set<string> s1;
		set<string> s2;
		int r = 0;
		while(j<N) {
	    	string w1, w2;
  			cin >> w1 >> w2;
  			count(w1, w2, s1, s2, r);
  			j++;
  		}
  		cout << "Case #" << ++i << ": " << r <<endl; 
	}
}