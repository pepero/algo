#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <assert.h>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        recurRestore(s, 4, "");
        return m_res;
    }
    
    void recurRestore(string s, int cnt, string prev){
        if ((cnt > 0 && s.empty()) || (cnt == 0 && !s.empty())){
            return;
        } 
        if (cnt == 0 && s.empty()){
            m_res.push_back(prev);
            return;
        } 
        else{
        	int length = s.length();
            for(int i = 1; i <= min(3, length); ++i){
                string s_prev = prev;
                int cnt_next = cnt;
                string curr = string (s.begin(), s.begin() + i); 
                string next = string (s.begin() + i, s.end());
                int ip = atoi(curr.c_str());
                if (ip <= 255 && ip >= 0) {
                    --cnt_next;
                    if (!s_prev.empty()) {
                      s_prev = s_prev + "."+curr;
                    } else{
                      s_prev = curr;
                    }
                    recurRestore(next, cnt_next, s_prev);
                } else{
                    return;
                }
            }
        }
    }
    
    vector<string> m_res;
};

int main(){
    Solution s;
    s.restoreIpAddresses("0000");
    cout << s.m_res[0];
}
