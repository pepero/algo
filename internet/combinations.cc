#include <vector>
#include <iostream>
#include <cstdio>

using namespace std;

typedef vector<vector<int> > vvi;
typedef vector <int> vi;
class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        results.clear();
        vi v(0);
        recCombine(v, n, k);
        return results;
    }
    void recCombine(vi &sofar, int n, int k){
        if(k==0 || n==k-1){
            results.push_back(sofar);
        }
        else{
            vi v_next(sofar);
            v_next.push_back(n);
            recCombine(v_next, n-1, k-1);
            recCombine(sofar, n-1, k);
        }
    }
    vvi results;
};

int main(){
    Solution s;
    s.combine(2, 1);
    typedef vector<vector<int> >::iterator VVit;
    typedef vector<int>::iterator Vit;
    for (VVit it1=s.results.begin(); it1!=s.results.end(); ++it1) {
        for (Vit it2=it1->begin(); it2!=it1->end(); ++it2) {
            printf("value is %d \n", *it2);
        }
    }
}
