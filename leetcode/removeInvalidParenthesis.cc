#include <set>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
  unordered_set<string> res;
  void f(const string &s, string ss, int k, int left, int right, int state) {
    if (k == s.size()) {
      if (! left && ! right && ! state)
        res.insert(ss);
      return;
    }
    if (s[k] == '(') {
      if (left > 0)
        f(s, ss, k+1, left-1, right, state);
      f(s, ss+'(', k+1, left, right, state+1);
    } else if (s[k] == ')') {
      if (right > 0)
        f(s, ss, k+1, left, right-1, state);
      if (state > 0)
        f(s, ss+')', k+1, left, right, state-1);
    } else
      f(s, ss+s[k], k+1, left, right, state);
  }
public:
  vector<string> removeInvalidParentheses(string s) {
    int l = 0, r = 0;
    for (auto c: s)
      if (c == '(')
        l++;
      else if (c == ')')
        l ? l-- : r++;
    f(s, "", 0, l, r, 0);
    return vector<string>(res.begin(), res.end());
  }
};

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        set<string> hash;
        int l = 0, r = 0;
        for(int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                l++; 
            } else if (s[i] == ')') {
                l ? l--:r++;
            }
        }
        helper(s, 0, l, r, 0, "", hash);
        vector<string> result(hash.begin(), hash.end());
        return result;
    }
    void helper(string& s, int start, int l, int r, int pair, string path, set<string>& hash){
        if (start == s.size()) {
            if (l==0 && r==0 && pair == 0) {
                hash.insert(path);
            }
            return;
        }
        if (s[start] == '(') {
            if (l>0) {
                helper (s, start+1, l-1, r, pair, path, hash);
            } 
            helper(s, start+1, l, r, pair+1, path+s[start],  hash);
        } else if (s[start] == ')') {
            if (r>0) {
                helper (s, start+1, l, r-1, pair, path, hash);
            } 
            helper(s, start+1, l, r, pair-1, path+s[start], hash);
        } else {
            helper(s, start+1, l, r, pair, path+s[start], hash);
        }
    }    
};

int main() {
    Solution s;
    vector<string> vs = s.removeInvalidParentheses("())()");
    for(int i = 0; i < vs.size(); ++i) {
        cout << vs[i] << endl;
    }
}