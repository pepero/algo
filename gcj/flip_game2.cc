#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool canWin(string s) {
        canW = false;
        rec(s, 1);
        return canW;
    }
    void rec(string& s, int cnt) {
        if (s.find("++")==string::npos) {
            if (cnt%2 == 0) {
                cout << "string is" << s << endl; 
                canW = true;
            }
            return;
        }
        for(int i =0; i+1 < s.size(); ++i) {
            if (!canW && s[i] == '+' && s[i+1] == '+') {
                s[i] = '-';
                s[i+1] = '-';
                rec(s, cnt+1);
                s[i] = '+';
                s[i+1] = '+';
            }
        }
    }
    bool canW;
};

int main() {
    Solution s;
    if (s.canWin("+++++++++")) {
        cout << "can win" <<endl;
    }
}