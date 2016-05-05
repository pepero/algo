#include <iostream>
#include <vector> 
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(); 
        int n = t.size();
        vector <vector<int>> vv(m+1, vector<int>(n+1));
        
        for(int i = 0; i < m+1; ++i) {
            for(int j=0; j < n+1; ++j) {
                if (i < j || i == 0) vv[i][j] = 0;
                else if (i > 0 && j == 0) vv[i][0] = 1;
                else if (i == j) vv[i][i] = s.substr(0, i) == t.substr(0, i) ? 1: 0;
                else if (i > j) vv[i][j] = vv[i-1][j] + ((s[i-1] == t[j-1]) ? vv[i-1][j-1]:0);  

                for (int p = 0; p < m+1; ++p) {
                    for(int q = 0; q < n+1; ++q) {
                        cout << " i " << p << " j "<< q << " val " << vv[p][q] << " ";
                    }
                    cout << endl;
                }
            }
        }
        return vv[m][n];
    }
};

int main(){
    Solution s;
    s.numDistinct("ccc", "c");
}