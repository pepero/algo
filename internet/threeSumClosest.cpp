#include <vector>
#include <map>
#include <hash_map>
#include <cstdio>
#include <algorithm>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
      // IMPORTANT: Please reset any member data you declared, as
      // the same Solution instance will be reused for each test case.
      int res = target ;
      sort(num.begin(), num.end());
      for (int i = 0; i < num.size(); ++i) {
        int k = i+1;
        int l = num.size() - 1;
        while(k<l) {
          sum = num[k] + num[l] + num[i];
          if (abs(sum - target) < abs (res - target)) {
            res = sum; 
          } else{
            if(sum-target <0) { 
              k++;
            } else{
              l--;
            }
          }          
        }
      }   
      return res;              
    }
};

int main(){
  int a[6] = {-1, 0, 1, 2, -1, -4};
  vector<int> v (a, a+sizeof (a) /sizeof(int));
  Solution s;
  s.threeSum(v);
  for(vector<vector<int> >::const_iterator it3 = s.vv.begin();
       it3!=s.vv.end(); ++it3) {
    for(vector<int>::const_iterator it4 = it3->begin(); 
         it4 != it3->end(); ++it4) {
      printf("val : %d\n", *it4);
    }
  }
}
