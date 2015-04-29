#include "iostream"
#include "string.h"
using namespace std;

string multiply(string num1, string num2) {
    int cnt1 = 0;
    int total = num1.size()+num2.size()+1;
    string str(total, '0');
    
    for(string::reverse_iterator rit1=num1.rbegin(); 
    rit1!=num1.rend(); ++rit1, ++cnt1)
    {
        int cnt2 = 0;
        int p = *rit1 -'0'; int carry = 0;
        for(string::reverse_iterator rit2=num2.rbegin(); 
        rit2!=num2.rend(); ++rit2, ++cnt2){
            int c= str[total-cnt1-cnt2-1] - '0';
            int q = *rit2 -'0';
            int m = p*q + carry + c;
            int resid = m%10;
            carry = m/10;
            str[total-cnt1-cnt2-1] = resid +'0';
        }
        int k = 0;
        while (carry > 0){
            int c= str[total-cnt1-cnt2-1-k] - '0';
            int m = carry + c;
            int resid = m%10;
            carry = m/10;
            str[total-cnt1-cnt2-1-k] = resid +'0';
            ++k;
        }
    }
    return str;
}

int main(){
    string str1 = "9", str2 = "9";
    cout << multiply(str1, str2);
}
