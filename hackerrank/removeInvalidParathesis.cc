#include <vector> 
#include <string>

using namespace std;

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> vs = helper(s);
        vector<string> results;
        vector<string> tmp;
        for(int i = 0; i < vs.size(); ++i) {
            tmp = helper(vs[i]);
            results.insert(results.end(), tmp.begin(), tmp.end());
        }
        return results;
    }
    vector<string> helper(string s){
        vector<string> result;
        int i, cnt = 0;
        for(i = 0; i < s.size(); ++i) {
            if (s[i] == '(') ++cnt;
            else if (s[i] == ')') cnt --;
            if (cnt < 0) break;
        }
        if (cnt<0) {
            for(int j = 0; j <= i; ++j) {
                if (s[j]==')' && (j ==0 || s[j-1] != ')')) {
                    string cur = s.substr(0, j) + s.substr(j+1, i);
                    string n = s.substr(i+1, s.size()-i-1);
                    vector<string> vs = removeInvalidParentheses(n);
                    for(int k = 0; k < vs.size();++k) {
                        result.push_back(cur+vs[i]);
                    }
                }
            }
        } 
        if (cnt == 0){
            string str = s.substr(cnt, s.size()-cnt);
            result.push_back(str);
        }
        return result;
    }
    
};

int main() {
    Solution s;
    s.removeInvalidParentheses("()())()");
}