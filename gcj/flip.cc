#include <string>
#include <iostream>
using namespace std;

int countFlips(string& s){
	int i = s.size()-1;
	for(; i>=0 && s[i] == '+'; i--);
	if (i==-1) return 0;
	char c = '-';
	int cnt = 1;
	for(int j = i; j >=0; --j) {
		if (s[j] != c) {
			++cnt;
			c = s[j];
		}
	}
	return cnt;
}

int main(){
	int T;
  	cin >> T;
  	int i = 0;
	while (i<T)	{
	    string s;
  		cin >> s;
  		cout << "Case #" << ++i << ": " << countFlips(s) <<endl; 
	}
}