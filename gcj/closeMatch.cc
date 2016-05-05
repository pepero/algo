#include <string>
#include <sstream>
#include <iostream>
using namespace std;

unsigned long long minv = 0;
string mina, minb;
int k[] = {0, 1, 0, 0};
void dfs(string& s1, string& s2, int p, int diff) {
	if(s1.size() == p) {
		stringstream ss1(s1), ss2(s2);
		unsigned long long a, b, c = 0;
		ss1 >> a;
		ss2 >> b;
		c = diff == 1 ? abs(a-b) : abs(b-a);
		if (c < minv) {
			minv = abs(a-b);
			mina = s1;
			minb = s2;
		}
		return;
	}
	if (diff == 1) {
		if (s1[p] == '?') s1[p] = '0';
		if (s2[p] == '?') s1[p] = '9';
		dfs(s1, s2, p+1, diff);
	} else if (diff == -1){
		if (s1[p] == '?') s1[p] = '9';
		if (s2[p] == '?') s1[p] = '0';
		dfs(s1, s2, p+1, diff);
	} else if (diff == 0) {
		if (s1[p] == '?' && s2[p] == '?') {
			for(int j = 0; j < 3; ++j) {
				s1[p] = k[j];
				s2[p] = k[j+1];
				dfs(s1, s2, p+1, k[j]-k[j+1]);
			}
		} else if (s1[p] == '?' && s2[p] != '?') {
			for(int j = -1; j <=1 ; ++j) {
				s1[p] = s2[p]+j;
				dfs(s1, s2, p+1, j);
			}
		} else if (s1[p] != '?' && s2[p] == '?') {
			for(int j = -1; j <=1 ; ++j) {
				s2[p] = s1[p]+j;
				dfs(s1, s2, p+1, -j);
			}
		} else {
			int diff_next = (s1[p]==s2[p]?0:(s1[p]>s2[p]?1:-1));
			dfs(s1, s2, diff_next);
		}
	}
}

int closeMatch(string& s1, string& s2) {
	dfs(s1, s2, 0, 0);
	return minv;
}

int main(){
	int T;
  	cin >> T;
  	int i = 0;
	while (i<T)	{
	    string s1, s2;
  		cin >> s1 >> s2;
  		minv = 0;
  		cout << "Case #" << ++i << ": " << closeMatch(s1, s2) <<endl; 
	}
}