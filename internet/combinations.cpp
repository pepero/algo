#include <vector>
#include <iostream>

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
        N = n;
        recCombine(v, n, k);
        return results;
    }
    void recCombine(vi &sofar, int n, int k){
        if(k==0){
            results.push_back(sofar);
        }
        else{
            vi v_next(sofar);
            v_next.push_back(N-n+1);
            recCombine(v_next, n-1, k-1);
            if(n-1 >=k) {
                recCombine(sofar, n-1, k);
            }
        }
    }

    int N;
    vvi results;
};

int main(){
    Solution s;
    s.combine(3, 2);
    for(vvi::iterator it=s.results.begin(); it!=s.results.end(); ++it) {
        for(vi::iterator it2=it->begin(); it2!=it->end(); ++it2) {
            cout << "value is" << *it2 << endl;
        }
    }
}


