#include <vector>
#include "stdio.h"

using namespace std;

typedef vector<vector<int> > vvi;
typedef vector<int> vi;
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        trgl = triangle;        
        return doMinTotal(0, 0);
    }
   
    int doMinTotal(int row, int pos){
    	int last_row = trgl.size()-1;
        if ((row+1 > vvmin.size()) ||  (pos+1 > vvmin[last_row - row].size())) {
            int i = trgl[row][pos];
            if (row+1==trgl.size()) {
                if (pos == 0) {
                    vi v;
                    v.push_back(i);
                    vvmin.push_back(v);
                } else {
                    vvmin[last_row - row].push_back(i);                                       
                }
            }  
            else {
                if (pos == 0) {
                    vi v;
                    int min1 = doMinTotal(row+1, pos) + i;
										int min2 = doMinTotal(row+1, pos+1) + i;
                    v.push_back(min(min1, min2));	
                    vvmin.push_back(v);
                } else {
				    				int min1 = doMinTotal(row+1, pos) + i;
										int min2 = doMinTotal(row+1, pos+1)+ i;
                    vvmin[last_row - row].push_back(min(min1, min2));
				}
            }
        }
        return vvmin[last_row - row][pos];
       
    }
    vvi trgl;
		vvi vvmin;
};

int main()
{
  vi v1(1, -1);
	vi v2, v3;
	v2.push_back(2);
	v2.push_back(3);
	v3.push_back(1);
	v3.push_back(-1);
	v3.push_back(-3);

  vvi vv;
	vv.push_back(v1);
	vv.push_back(v2);
	vv.push_back(v3);
	
	Solution s;
	int sum = s.minimumTotal(vv);
	printf("mini sum is %d \n", sum);
	for (vvi::iterator it1=s.vvmin.begin(); it1!=s.vvmin.end(); ++it1) {
				for (vi::iterator it2=it1->begin(); it2!=it1->end(); ++it2) {
					printf("value is %d \n", *it2);			
				}
		}

}



