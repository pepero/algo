
#include <vector>

using namespace std;

class Solution {
public:    
    vector<vector<int> > createData(vector<int>& num) {
        vector<int> v(100, 10);
        vv.push_back(v);         
        vv.push_back(num);   
        return vv;
    }
    
    vector<vector<int> > vv;
};

int main(){
    Solution s;
    vector<int> vt (1, 1);
    s.createData(vt);
}
