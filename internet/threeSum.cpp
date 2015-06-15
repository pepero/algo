#include <vector>
#include <map>
#include <cstdio>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > threeSumIt(vector<int> &num) {
      // IMPORTANT: Please reset any member data you declared, as
      // the same Solution instance will be reused for each test case.
      map<int, int> numCnt;
      for (vector<int>::const_iterator it = num.begin();
            it !=num.end(); ++it) {
        numCnt[*it]++;
      }
      for (vector<int>::const_iterator it1 = num.begin();
            it1 !=num.end(); ++it1) {
        numCnt[*it1] --;
        for (vector<int>::const_iterator it2 = num.begin();
            it2 !=num.end(); ++it2) {
          if (it1 == it2) continue;
          numCnt[*it2]--;
          if (numCnt[-*it2-*it1] > 0) {
            vector <int> v;
            v.push_back(*it1);
            v.push_back(*it2);
            v.push_back(-*it1-*it2);
            sort(v.begin(), v.end());
            vv.push_back(v);
          }      
          numCnt[*it2]++;
        }
        numCnt[*it1]++;
      }      
      return vv;              
    }

//  vector<vector<int> > threeSum(vector<int> &num) {
//    // IMPORTANT: Please reset any member data you declared, as
//    // the same Solution instance will be reused for each test case.
//    sort(num.begin(), num.end());
//    for(int i = 0; i < num.size(); ++i) {
//      int k = i+1;
//      int l = num.size() -1;
//      while (k < l) {
//        int sum = num[i] + num[k] + num[l];
//        if (sum == 0) {
//          vector v;
//          v.push_back(num[i]);
//          v.push_back(num[k]);
//          v.push_back(num[l]);
//          if (vv.back() != v) {
//            vv.push_back(v);
//          }
//        } else if (sum < 0) {
//          k++;
//        } else{
//          l--;
//        }
//      }
//    }
//    return vv;
//  }
    vector<vector<int> > vv;
};

class Solution2 {
public:
     vector<vector<int> > threeSum(vector<int> &num) {
      // IMPORTANT: Please reset any member data you declared, as
      // the same Solution instance will be reused for each test case.
      vv.clear();
      sort(num.begin(), num.end());
      for(int i = 0; i < num.size(); ++i) {
        if (i > 0 && num[i] == num[i - 1])  continue; 
        int k = i+1;
        int l = num.size() -1;
        while (k < l) {
          int sum = num[i] + num[k] + num[l];
          if (sum == 0) {
            vector<int> v;
            v.push_back(num[i]);
            v.push_back(num[k]);
            v.push_back(num[l]);            
            if (!vv.empty()) {
                if (vv.back() != v) {
                    vv.push_back(v);
                }
            } 
            else {
                vv.push_back(v);
            }
            k++;
            l--;           
          } else if (sum < 0) {
            k++;
          } else{
            l--;
          }          
        }
      }
      return vv;              
    }
    vector<vector<int> > vv;
};


int main(){
  int a[] = {-1, 0, 1, 1, 1, 1, 2, -1, -1, -1, -4};
  vector<int> v (a, a+sizeof (a) /sizeof(int));
  Solution2 s;
  s.threeSum(v);
  for(vector<vector<int> >::const_iterator it3 = s.vv.begin();
       it3!=s.vv.end(); ++it3) {
    for(vector<int>::const_iterator it4 = it3->begin(); 
         it4 != it3->end(); ++it4) {
      printf("val : %d\n", *it4);
    }
  }
}
