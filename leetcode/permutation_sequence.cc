#include <vector>
#include <iostream>
using namespace std;

string getPermutation(int n, int k) {
        string str (n, ' ');
        vector<int> vm (n, 0);
        int fact=1;
        for(int i=1; i<n; ++i){
            fact*=i;
            vm[i-1] = i; 
        }
        vm[n-1] = n;

        int cur = n-1;
        while(cur){
            int p = k/fact;
            k = k%fact;
            if (p >0 && k==0){
                --p;
            } 
            else if (p == 0 && k ==0){
                p = cur;
            }
            str[n-1-cur] = vm[p];
            vm.erase(vm.begin() + p);
            fact = fact/cur;
            --cur;
        }
        str[n-1] = vm[0]+'0';
        return str;
    }
int main(){
    cout << getPermutation(2, 1) << endl;   
}