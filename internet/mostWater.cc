class Solution {
public:
    int maxArea(vector<int> &height) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int left = 0;
        int right = height.size()-1;
        int area = 0;
        int maxi = 0;

        while (left < right){
            area = min(height[left], height[right])* abs(height[left] - height[right]);
            if (area > maxi) {
                maxi = area;
            }
            if (height[left] < height[right]) {
                left++;
            } else{
                right--;
            }            
        }
        return maxi;
    }
};
