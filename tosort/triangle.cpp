#include <vector>
#include <cstdio>

using namespace std;

typedef vector<vector<int> > VVI;
typedef vector<int> VI;

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = triangle.size();
        vector<int> vmin(n, 0);
        while (n--){
            for (int i=0; i<=n; i++){
            vmin[i]=triangle[n][i]+min(vmin[i], vmin[i+1]);}
        }
        return vmin[0];
    }
};

int main(){

    // [[-9],[-8,0],[-3,2,5],[6,3,0,-4],[-2,-9,-5,-8,6],[0,-5,0,-2,-1,5],[0,6,-1,-5,-8,6,-5],[-8,-5,-9,-8,-4,-3,-5,7]]

    int x1[1] = { -9 };
    int x2[2] = { -8,0 };
    int x3[3] = { -3,2,5 };
    int x4[4] = { 6,3,0,-4 };
    int x5[5] = { -2,-9,-5,-8,6 };
    int x6[6] = { 0,-5,0,-2,-1,5 };
    int x7[7] = { 0,6,-1,-5,-8,6,-5 };
    int x8[8] = { -8,-5,-9,-8,-4,-3,-5,7};

    VI v1(x1, x1 + sizeof x1 / sizeof x1[0]);
    VI v2(x2, x2 + sizeof x2 / sizeof x2[0]);
    VI v3(x3, x3 + sizeof x3 / sizeof x3[0]);
    VI v4(x4, x4 + sizeof x4 / sizeof x4[0]);
    VI v5(x5, x5 + sizeof x5 / sizeof x5[0]);
    VI v6(x6, x6 + sizeof x6 / sizeof x6[0]);
    VI v7(x7, x7 + sizeof x7 / sizeof x7[0]);
    VI v8(x8, x8 + sizeof x8 / sizeof x8[0]);

    VVI vvi;
    vvi.push_back(v1);
    vvi.push_back(v2);
    vvi.push_back(v3);
    vvi.push_back(v4);
    vvi.push_back(v5);
    vvi.push_back(v6);
    vvi.push_back(v7);
    vvi.push_back(v8);

    Solution s;
    int i = s.minimumTotal(vvi);
    printf("min total is %d\n", i);
}
