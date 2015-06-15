#include "stdio.h"
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> v(0);
        doPermute(v, num);    
        return vv;
    }
   
    void doPermute(vector<int> &v, vector<int> &num) {
        if(num.empty()) {
            vv.push_back(v);         
            return;     
        } else {
            for (int i = 0; i < num.size(); i++)
            {
                int toAdd = num[i];
                vector<int> rest(num);
                rest.erase(rest.begin()+i);                  
                vector<int> prefix(v);
                prefix.push_back(toAdd);
                doPermute(prefix, rest);
            }               
        }
    }
   
    vector<vector<int> > vv;
};

int main(){
    Solution s;
    
		int x[2]={0, 1};
		vector<int> vt(x, x + sizeof x / sizeof x[0]);
    s.permute(vt);
		typedef vector<vector<int> >::iterator VVit;
    typedef vector<int>::iterator Vit;
		for (VVit it1=s.vv.begin(); it1!=s.vv.end(); ++it1) {
				for (Vit it2=it1->begin(); it2!=it1->end(); ++it2) {
					printf("value is %d \n", *it2);			
				}
		}
}


