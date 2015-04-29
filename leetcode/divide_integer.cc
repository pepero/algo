#include "iostream"
#include "climits"
#include <stdlib.h> 
#include <stdio.h> 

using namespace std;
int divide(int dividend, int divisor) {
    if (divisor == 0) return INT_MAX;
    int cnt = 0;
    unsigned int absDividend = (dividend == INT_MIN)? 2147483648:abs(dividend);
    unsigned int absDivisor = (divisor == INT_MIN)? 2147483648:abs(divisor);

    unsigned int res = 0;
    unsigned int dvs = absDivisor;
    while(dvs <= absDividend){
        dvs <<= 1;
        ++cnt;
        if(dvs == absDividend){
            res += (1 << (cnt));
            break;
        }
        if(dvs > absDividend){
            absDividend = absDividend-(dvs >> 1); 
            res += (1 << (cnt-1));
            dvs = absDivisor;
            cnt = 0;
        }
    }
    if ((dividend >0 && divisor >0) || 
        (dividend <0 && divisor <0))
    {
        int result = res;
        return result;
    } else{
        int result = 0-res;
        return result;
    }
}



int main(){
    int i = INT_MIN;
    unsigned int ui= i;
    long long ll = i;
    cout << ui << "abs is " << abs(ui) << endl;
    cout << ll << "abs is " << labs(ll) << endl;
    

    cout << "--------" << endl;
    unsigned char*p = (unsigned char *)&ui;
    for (int k = 0; k < sizeof ui; k++)
        printf("%02x ", p[k]);

    cout << endl;
    unsigned char*q = (unsigned char *)&ll;
    for (int k = 0; k < sizeof ll; k++)
        printf("%02x ", q[k]);


 }

