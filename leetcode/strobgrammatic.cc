#include <vector>
#include <string>
#include <map>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        vector<string> vs1;
        vs1.push_back("");
        m[0] = vs1;
        vs1.push_back("0");
        vs1.push_back("1");
        vs1.push_back("8");
        m[1] = vs1;
        if (n<2) return m[n];
        for(int i = 2; i <=n; ++i) {
            vector<string> vs; 
            vector<string>& vs_prev = m[i-2];
            for(int j = 0; j < vs_prev.size(); ++j) {
                const string& s = vs_prev[j];
                if (i != n) {
                    string str0 = "0" + s + "0"; 
                    vs.push_back(str0);
                }
                string str1 = "1" + s + "1";
                string str6 = "6" + s + "9"; 
                string str8 = "8" + s + "8"; 
                string str9 = "9" + s + "6"; 
                vs.push_back(str1);
                vs.push_back(str6);
                vs.push_back(str8);
                vs.push_back(str9);
            }
            cout << "i is " << i << endl;
            for (int k = 0; k < vs.size(); ++k) {
                cout << vs[k] <<", ";
            }
            cout <<endl;
            m[i] = vs;
        }
        return m[n];
    }
    map<int, vector<string> > m;
};

int main(){
    Solution s;
    vector<string> vs = s.findStrobogrammatic(4);
    for(int i = 0; i < vs.size(); ++i) {
        cout << vs[i]<<endl;
    }
}