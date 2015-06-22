#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef vector<vector<int> > vvi;
typedef vector<int> vi;
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        results.clear();
        doSubsets(S);
        return results;
    }
        
    void doSubsets(vector<int> &S) {
        if(S.empty()){
            vi v;
            results.push_back(v);
        }
        else {
            int value = S.back();
            vi rest(S.begin(), S.end()-1);
            doSubsets(rest);
            int size = results.size();
            for (int i=0; i<size;i++){
                vi v = results[i];
                v.push_back(value);
                sort(v.begin(), v.end());
                results.push_back(v);
            }
        }
    }
    vvi results;    
};


int main(){
    Solution s;
    vi v(1, 1);
    v.push_back(2);
    v.push_back(3);
    s.subsets(v);
    for(vvi::iterator it=s.results.begin(); it!=s.results.end(); ++it) {
        for(vi::iterator it2=it->begin(); it2!=it->end(); ++it2) {
            cout << "value is" << *it2 << endl;
        }
    }
}


