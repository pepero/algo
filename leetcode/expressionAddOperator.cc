#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<string> addOperators(string num, int target) {
    	result.clear();
    	string s = "";
    	recursive(num, 0, 0, 0, target, s);
    	return result;
    }

    void recursive(string& s, long tot, long prev, int start, int target, string sofar) {
    	if (start == s.size()) {
    		if (tot == target) {
    			result.push_back(sofar);
    		}
    		return;
    	} 
    	for(int i=start; i<s.size(); i++) {
            if (s[start] == 0 && i > start) break;
    	    string s_next = s.substr(start, i-start+1);
    	    long next = stol(s_next);
    	    if (start==0) {
    	        recursive(s, tot+next, next, i+1, target, sofar+s_next);
    	    } else {
        	    recursive(s, tot+next, next, i+1, target, sofar+'+'+s_next);
        	    recursive(s, tot-next, -next, i+1, target, sofar+'-'+s_next);
        	    recursive(s, tot-prev+prev*next, prev*next, i+1, target, sofar+'*'+s_next);
    	    }
    	}
    }
    vector<string> result;
};

int main() {
    Solution s;
    s.addOperators("3456237490", 9191);
    for(auto e:s.result) {
        cout << e<<endl;
    }
}