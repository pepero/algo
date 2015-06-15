#include <vector>
#include "stdio.h"

using namespace std;

typedef vector<vector<int> > vvi;
typedef vector<int> vi;

class Solution {
public:
    int min;
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int sum = 0;
        int pos = 0; 
        min = INT_MAX;
        doMinTotal(triangle,sum, pos);
        return min;
    }
    
    // if void doMinTotal(vvi trgl, int sum, int pos) then
		// "memory limit exceeds"
 
    void doMinTotal(vvi trgl, int sum, int pos){
        if (trgl.empty()) {
            if (sum < min) min=sum;            
        }
        else {
            
            // special case for top row
            if (trgl.begin()->size()==1) {
                int sum_next = sum + trgl[0][0]; 
                vvi trgl_next (trgl.begin()+1, trgl.end());
                int pos_next = pos;
                doMinTotal(trgl_next, sum_next, pos_next);
            }
            else{                
                for(int i = pos; i <= pos+1; i++) {
                    int sum_next = sum + trgl[0][i];
                    vvi trgl_next(trgl.begin()+1, trgl.end());
                    int pos_next = i;
                    doMinTotal(trgl_next, sum_next, pos_next);
                }               
            }
        }
        
    }
};

int main(){
 Solution s;
 vi v1(1, 1);
 vi v2;
 v2.push_back(2);
 v2.push_back(3);
 vvi vv;
 vv.push_back(v1);
 vv.push_back(v2);
 int mini = s.minimumTotal(vv);
 printf ("mini total is %d \n", mini);
} 


