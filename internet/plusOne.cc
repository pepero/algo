#include <iostream>
#include <vector>

using namespace std;
typedef vector<vector<int> > VVInt;
typedef vector<int> VInt;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (digits.size() == 0) return digits;	
        if (digits[0]>=0) {
            int incr = 1;
            for (VInt::reverse_iterator rit = digits.rbegin(); rit !=digits.rend(); ++rit)
            {
                int digi = *rit + incr;
                if (digi == 10) {incr = 1;}
                else incr = 0;
                *rit = digi%10;
            } 
            if (incr == 1) digits.insert(digits.begin(), 1);
        } else {
            int decr = 1;
            for (vector<int>::reverse_iterator rit = digits.rbegin();
            rit !=digits.rend(); ++rit)
            {
                if (rit == digits.rend()-1) {*rit +=decr; continue;}
                if (*rit != 0) {*rit -= decr; break;}
                else {
                    *rit = 9;
                    decr = 1;
                }
            } 
        }
        return digits;        
    }
};

int main(){
    vector<int> vi(4, 1);
    Solution s;
    s.plusOne(vi);
}


