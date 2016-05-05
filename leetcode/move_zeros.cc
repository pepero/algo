#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int index = 0;
        for (int i = 0; i < nums.size(); ++i){
            if (nums[i]!=0) {
            	nums[index] = nums[i];
            	index++;
            }
        }
        for(int j = index; j< nums.size(); ++j) {
        	nums[j] = 0;
        }
    }
};

int main(){
	Solution s;
	vector<int> v;
	v.push_back(0);
	v.push_back(1);
	v.push_back(0);
	v.push_back(3);
	v.push_back(12);
	s.moveZeroes(v);
	for (int i=0; i < v.size(); ++i) {
		std::cout << v[i] << std::endl;
	}
}
