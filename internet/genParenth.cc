#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vStr.clear();
        string s = "";
        if (n > 0) {
            recGen(s, n, n);
        }
        return vStr;
    }
    
    void recGen(string &sofar, int cntS, int cntE) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (cntE == 0){ vStr.push_back(sofar); return;}
        else{
            if (cntS < cntE) {
                if (cntS > 0) { 
                    string str_next = sofar + "(";
                    recGen(str_next, cntS-1, cntE);
                } 
                string str_next = sofar + ")";
                recGen(str_next, cntS, cntE-1);
            }
            if (cntS == cntE) {
                string str_next = sofar + "(";
                recGen(str_next, cntS-1, cntE);
            }
        }
    }
    vector<string> vStr;
};

int main(){
    Solution s;
    s.generateParenthesis(3);
    for (vector<string>::const_iterator it = s.vStr.begin();
          it!= s.vStr.end(); ++it) {
        cout << *it << endl;
    }
}
