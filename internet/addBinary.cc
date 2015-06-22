#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int size = max(a.size(), b.size());
        int ia = 0, ib = 0, va = 0, vb = 0, incr = 0;
        string c = "";
        for(int i=0; i<size; ++i){
          ia= a.size()-1-i;
          ib= b.size()-1-i;
          if(ia>=0) {
            va = a[ia];
          } else{
            va = 0;
          }
          if(ib>=0) {
            vb = b[ib];
          } else{
            vb = 0;
          }
          switch ((va + vb + incr)%'0'){
            case 3: 
              incr = '1';
              c += '1';
              break;
            case 2: 
              incr = '1';
              c += '0';
              break;
            case 1: 
              incr = 0;
              c += '1';
              break;
            case 0: 
              incr = 0;
              c += '0';
              break;          
          }
        }
        if(incr =='1') {
          c += '1';
        }
        reverse(c.begin(), c.end());
        return c;
    }
};

int main(){
  Solution s;
  string res = s.addBinary("0", "0");
  cout << res << endl;
}
