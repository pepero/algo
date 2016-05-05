#include <string>
#include <fstream>
#include <bitset>
#include <iostream>
using namespace std;


string add (string& s1, string& s2) {
    string s;
    int i, j, inc = 0, rem = 0;
    for(i = s1.size()-1, j = s2.size()-1; i >=0 || j >= 0;) {
        int a = (i==-1? 0 : s1[i--]-'0');
        int b = (j==-1? 0 : s2[j--]-'0');
        rem = (a + b + inc)%10;
        s = char (rem + '0') + s;
        inc = (a + b + inc)/10;
        if (i == -1 && j == -1 && inc > 0) {
            s = char (inc + '0') + s; 
        }
    }
    return s;
}

string count (int num) {	
	if (num == 0) return 0;
	bitset<10> bs;
	string inc = to_string(num);
	string last = inc;
	for(int i=0; i < last.size(); ++i){
		bs.set(last[i]-'0', true);
		if (bs.count() == 10) {
			return last;
		}
		if (i == last.size()-1) {
			last = add(last, inc); 
			i = -1; 
		}
	}
}

int main(){
	int T;
  	cin >> T;
  	int i = 0;
	while (i<T)	{
	    int num;
  		cin >> num;
  		cout << "Case #" << ++i << ": " << (num==0?"INSOMNIA":count(num)) <<endl; 
	}
}