#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>v(n);
        v[0] = 1;
        for(int i = 1; i < n; ++i) {
            int maxL = 0;
            for(int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    maxL = max(maxL, v[j]);
                }
            }
            v[i] = maxL+1;
        }
        return *max_element(v.begin(), v.end());
    }
};

int main() {
    Solution s;
    int a[] = {3, 4, 0, 1};
    vector<int> vi(a, a+4);
    cout << s.lengthOfLIS(vi)<<endl;
}