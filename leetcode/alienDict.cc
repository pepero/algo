#include <map>
#include <stack>
#include <vector>
#include <set>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    string alienOrder(vector<string>& words) {
        vector<bool> v1(26, false);
        onStack = v1; 
        marked = v1;
        hasCycle = false;
        for(int i= 0; i < words.size()-1;++i) {
            diff(words[i], words[i+1]);
        }
        
        visit();
        if (hasCycle) {
            //cout << "has cycle" << endl;
            return "";
        }
        string s;
        while(!reversePost.empty()) {
            s += reversePost.top();
            reversePost.pop();
        }
        return s;
        
    }
    void diff(string& s1, string&s2) {
        bool found = false;
        for(int i = 0; i < max(s1.size(), s2.size()); ++i) {
            if (i < s1.size() && m.count(s1[i]) == 0) {
                m[s1[i]] = set<char>();
            }
            if (i < s2.size() && m.count(s2[i]) == 0) {
                m[s2[i]] = set<char>();
            }
            if (i < s1.size() && i < s2.size() && s1[i] != s2[i] && !found) {
                m[s1[i]].insert(s2[i]);
                found = true;
            }
        }
    }
    
    void visit(){
        for(auto e : m) {
            //cout << "visit " << e.first<< endl;
            if (!marked[e.first-'a']) {
                dfs(e.first);
            } else{
                //cout << e.first << " has been visited" << endl; 
            }
        }
    }
    
    void dfs(char c) {
        cout << "dfs " << c << endl; 
        onStack[c-'a'] = true;
        marked[c-'a'] = true;
        for(auto adj : m[c]) {
            if (hasCycle) {
                cout << "cycle exists" << endl;
                return; 
            }
            else if (!marked[adj-'a']) {
                dfs(adj);
            } else if (onStack[adj-'a']){
                hasCycle = true;
            }
        }
        reversePost.push(c),
        onStack[c-'a'] = false;
    }
    stack<char> reversePost;
    bool hasCycle;
    vector<bool> onStack;
    vector<bool> marked;
    map<char, set<char>> m;
};

int main() {
    Solution s;
    vector<string> vs = {"wrt","wrf","er","ett","rftt"};
    cout << s.alienOrder(vs) << endl;
}