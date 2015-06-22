#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int cnt = 1;
        int max = 1;
        unordered_map<int, bool> table;
        for (int i = 0; i < num.size(); ++i){
            table[num[i]] = true;
        }
        for (int i = 0; i < num.size(); ++i){
            while (table[++num[i]]) {
                cnt++;
            }
            if (cnt > max) max = cnt;
            cnt = 1;
        }
        return max;
    }
};

int main(){
    Solution s;
    int a [] = {100, 200, 1, 2, 3, 4};
    vector<int> v (a, a+sizeof a /sizeof (int));
    cout << s.longestConsecutive(v) << endl;
}
