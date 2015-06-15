#include <vector> 
#include <iostream> 
using namespace std;
typedef vector<vector<int> > VVInt;
typedef vector<int> VInt;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int i = 0;
        int j = n-1;
        int p = 0;
        int cnt = 1;
        vector<int> v(n, 0);
        vector<vector<int> > vv(n, v);
        for (int i = 0, j=n-1; i<=j; i++, j--) {
            // left->right
            for (int p = i; p <= j; p++) {
                vv[i][p] = cnt++;
            }
            // up->down
            for (int p = i+1; p <= j; p++) {
                vv[p][j] = cnt++;
            }
            // right->left
            for (int p = j-1; p >=i; p--) {
                vv[j][p] = cnt++;
            }
            // bottom->up
            for (int p = j-1; p >=i+1; p--) {
                vv[p][i] = cnt++;
            }            
        }        
        return vv;
    }
};

class Solution1 {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> v;
        if (matrix.empty()) return v;
        int p = 0;
        int n = matrix.size();
        int m = matrix[0].size();

        for (int i= 0, j = m-1, k = n-1; (i <= j) && (i <= k) ; i++, j--, k--){
             // left->right
            for (int p = i; p <= j; p++) {
                v.push_back(matrix[i][p]);
            }
            // up->down
            for (int p = i+1; p <= k; p++) {

                v.push_back(matrix[p][j]);
            }
            // right->left
            for (int p = j-1; p >=i; p--) {
                v.push_back(matrix[k][p]);
            }
            // bottom->up
            for (int p = k-1; p >=i+1; p--) {
                v.push_back(matrix[p][i]);
            }     
        }
        return v;
    }
};

int main(){
    Solution s;
    VVInt vvi = s.generateMatrix(3);
    for (VVInt::const_iterator it1=vvi.begin(); it1!=vvi.end(); ++it1) {
        for (VInt::const_iterator it2=it1->begin(); it2!=it1->end(); ++it2) {
            cout << "value is" << *it2 << " ";
        }
        cout << endl;
    }

}

