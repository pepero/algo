class Solution {
public:
    int trap(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        left [0] = 0;
        right[n-1] = 0;
        int maxL = 0;
        int maxR = 0;
        int sum = 0;
        for(int i = 1; i < n-1; ++i) {
            if (A[i-1] > maxL) {
                maxL = A[i-1]
            }
            left[i] = maxL;

            if (A[n-i] > maxR) {
                maxR = A[n-i]
            }
            right[n-i-1] = maxR;
        }
        
        for (int i = 1; i < n-1; ++i) {
            int level = min (maxL[i], maxR[i]);
            sum += level - A[i];
        }
        return sum;
    }
};


