#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef vector<vector<int> > vvi;
typedef vector<int> vi;
class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        result.clear();
        sort(S.begin(), S.end());
        recSubset(S);
        return result;
    }
    
    int recSubset(vector<int> &v){
        if (v.empty()){
            vector<int> vi;
            result.push_back(vi);
            return 0;
        } else{
            int val = v.back();
            vector<int> rest (v.begin(), v.end()-1);
            int lastStart = recSubset(rest);
            int currStart = result.size();
            int start = 0;
            if (!rest.empty() && val == rest.back()) start = lastStart;
            for(int i = start; i < currStart; ++i){
                vector<int> v_next = result[i];
                v_next.push_back(val);
                result.push_back(v_next);
            }
            return currStart;
        }
    }
    vector<vector<int> > result;
};

int main(){
    Solution s;
    vi v(1, 1);
    v.push_back(2);
    v.push_back(2);
    s.subsetsWithDup(v);
    for(vvi::iterator it=s.result.begin(); it!=s.result.end(); ++it) {
        for(vi::iterator it2=it->begin(); it2!=it->end(); ++it2) {
            cout << "value is" << *it2 << endl;
        }
    }
}


