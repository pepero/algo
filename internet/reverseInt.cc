#include<iostream>
#include<sstream>
#include<string>

using namespace std;

class Solution {
public:
    int reverseInt(int x) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int j = 0;
        while(x!=0){
            j = 10*j + x%10;
            x = x/10;
        }
        return j;
    }

    string reverseIntToStr(int x) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        stringstream ss;
        bool start = false;
        while(x!=0){
            if(!start) {
                int i=x%10;
                if(i!=0) {
                    start = true;
                } else{
                    x = x/10;
                }
            }
            if (start){
                int i = x%10;
                ss<< x%10;
                x = x/10;
            }
        }
        return ss.str();
    }
};

int main(){

    Solution s;
    cout << s.reverseInt(100) << endl;
    cout << s.reverseIntToStr(2147483647)<< endl;
    cout << s.reverseInt(-100) << endl;
    cout << s.reverseIntToStr(-100) << endl;
}

// 1. -7 % 3 = -1
// 2. 7 % -3 = 1;
// 3. catch int overflow
// in-place


