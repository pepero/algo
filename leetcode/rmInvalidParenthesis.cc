#include <vector> 
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        string empty1 = "", empty2 = "", rs;
        vector<string> tmp;
        vector<string> results;
        helper(s, 0, 0, tmp, make_pair('(', ')'));
        for(int i = 0; i < tmp.size(); ++i) {
            cout << "string is" << tmp[i] <<endl;
            reverse(tmp[i].begin(), tmp[i].end());
            cout << "after reverse is" << tmp[i] <<endl;
            helper(tmp[i], 0, 0, results, make_pair(')', '('));
        }
        for(int k = 0; k < results.size(); ++k) {
            reverse(results[k].begin(), results[k].end());
        }
        return results;
    }
    void helper(string sofar, int i_start, int j_start, vector<string>& results, pair<char, char> p){
        if (i_start == sofar.size()) {
            cout << "push_back " << sofar<<endl; 
            results.push_back(sofar);
            return;
        }
        int i, cnt = 0;
        for(i = i_start; i < sofar.size(); ++i) {
            if (sofar[i] == p.first) ++cnt;
            else if (sofar[i] == p.second) cnt --;
            if (cnt < 0) break;
        }
        if (cnt<0) {
            for(int j = j_start; j <= i; ++j) {
                if (sofar[j]==p.second && (j == j_start || sofar[j-1] != p.second)) {
                    string cur = sofar.substr(0, j) + sofar.substr(j+1, sofar.size()-1-j);
                    cout << "i is " << i <<" j is " << j << "cur is "<< cur << endl;
                    helper(cur, i, j, results, p);
                }
            }
        } else {
            results.push_back(sofar);
        }
    }    
};

int main() {
    Solution s;
    vector<string> vs = s.removeInvalidParentheses(")d))");
    for(int i = 0; i < vs.size(); ++i) {
        cout << vs[i] << endl;
    }
}