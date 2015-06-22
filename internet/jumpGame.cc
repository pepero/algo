#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    bool canJump(int A[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        result = false;
        if (n <= 1) return true;
        for(int i = 1; i <= A[0]; ++i) {
          int *A_next = A + i;
          int n_next = n - i;
          result |= canJump(A_next, n_next);
        }
        return result;        
    }

    int jump(int A[], int n) {
      mini = INT_MAX;
      jumpHelper (A, n, 0);
      return mini;        
    }
    
    void jumpHelper(int A[], int n, int sum) {
        if(n <=1) {
          if (sum < mini) {
            mini = sum;
          }
          return;
        } 
        for(int i = 1; i <= A[0]; ++i) {
          int *A_next = A + i;
          int n_next = n - i;
          int sum_next = sum+1;
          jumpHelper(A_next, n_next, sum_next);
        }         
    }
    bool result;
    int mini;
};

int main(){
  Solution s;
  int a[] = {2,3,1,1,4};
  int b[] = {3,2,1,0,4};
    cout << s.jump(a, 5) << endl;
}
