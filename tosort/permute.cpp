
// #include <vector>
#include <cstdio>
#include <algorithm>

void swapChars(char* a, char* b){
    char temp = *b;
    *b = *a;
    *a = temp;
}


class Solution {
public:
//  vector<vector<int> > permute(vector<int> &num) {
//      // Start typing your C/C++ solution below
//      // DO NOT write int main() function
//      vector<int> v(0);
//      doPermute(v, num);
//      return vv;
//  }
//
//  void doPermute(vector<int> &v, vector<int> &num) {
//      if(num.empty()) {
//          vv.push_back(v);
//          return;
//      } else {
//          for (int i = 0; i < num.size(); i++)
//          {
//              vector<int> rest(num);
//              vector<int> pref(v);
//              int toAdd = num[i];
//              rest.erase(rest.begin()+i);
//              pref.push_back(toAdd);
//              doPermute(pref, rest);
//          }
//      }
//  }

//  void doPermuteUni(Vi &pref, Vi &num) {
//      if (num.empty()) {
//          vv.push_back(pref);
//      } else {
//          vector<int> visited(0);
//          for (int i=0; i<num.size();i++) {
//              if (find(visited.begin(), visited.end(), num[i])==visited.end()) {
//                  visited.push_back(num[i]);
//
//                  // explore
//                  Vi rest(num);
//                  Vi prefix(pref);
//                  rest.erase(rest.begin()+i);
//                  prefix.push_back(num[i]);
//                  doPermuteUni(prefix, rest);
//              }
//          }
//      }
//  }
    

    void permute2(char *a, int i, int n)
    {
       int j;
       if (i == n)
         printf("%s\n", a);
       else
       {
           for (j = i; j <= n; j++)
           {
              swapChars((a+i), (a+j));
              permute2(a, i+1, n);
              swapChars((a+i), (a+j)); //backtrack
           }
       }
    } 


    // vector<vector<int> > vv;
};

int main(){
    Solution s;
    // vector<int> vt (1, 1);
    // s.permute(vt);
    // 
    char str[]= "abcd";
    //swapChars(str, str+3); 
    s.permute2(str, 0, 3);
}
