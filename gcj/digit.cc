#include <string>
#include <iostream>
#include <map>
using namespace std;


string phone(string s) {
	map<int, int> m;  
	int c[10] = {0};
	for(int i = 0; i< s.size(); ++i) {
		m[s[i]]++;
	}
	if (m['Z'] > 0) {
		m['E']-=m['Z'];
		m['R']-=m['Z'];
		m['O']-=m['Z'];
		c[0] = m['Z'] ;
	} 
	if (m['W'] > 0) {
		m['T']-=m['W'];
		m['O']-=m['W'];
		c[2] = m['W'] ;
	}  
	if (m['U'] > 0) {
		m['F']-=m['U'];
		m['O']-=m['U'];
		m['R']-=m['U'];
		c[4] = m['U'] ;
	} 
	if (m['X'] > 0) {
		m['S']-=m['X'];
		m['I']-=m['X'];
		c[6] = m['X'] ;
	} 
	if (m['G'] > 0) {
		m['E']-=m['G'];
		m['I']-=m['G'];
		m['H']-=m['G'];
		m['T']-=m['G'];
		c[8] = m['G'] ;
	} 
	if (m['O'] > 0) {
		m['E']-=m['O'];
		m['N']-=m['O'];
		c[1] = m['O'] ;
	}
	if (m['H'] > 0) {
		m['T']-=m['H'];
		m['R']-=m['H'];
		m['E']-=2*m['H'];
		c[3] = m['H'] ;
	}
	if (m['F'] > 0) {
		m['E']-=m['F'];
		m['I']-=m['F'];
		m['V']-=m['F'];
		c[5] = m['F'] ;
	}
	if (m['S'] > 0) {
		m['E']-=2*m['S'];
		m['N']-=m['S'];
		m['V']-=m['S'];
		c[7] = m['S'] ;
	}
	if (m['I'] > 0) {
		c[9] = m['I'] ;
	}
	string r;
	for(int i = 0; i < 10; ++i) {
		if (c[i] > 0) {
			for(int j = 0; j < c[i]; ++j) {
				r += to_string(i);
			}
		}
	}
	return r;
}

int main() {
	int T;
  	cin >> T;
  	int i = 0;
	while (i<T)	{
	    string s;
  		cin >> s;
  		cout << "Case #" << ++i << ": " << phone(s) <<endl; 
	}
}