/*
Given : An unsorted array A of integers                                              
Input : An integer k                                                                 
                                                                                     
Output : All the two element set with sum of elements in each set equal to k in O(n).
                                                                                     
Example:                                                                             
                                                                                     
A = {3,4,5,1,4,2}                                                                    
                                                                                     
Input : 6                                                                            
Output : {3,3}, {5,1}, {4,2} 
 
follow-up: what if {3, 3} is not allowed? 
int cnt[target+1] = 0; 
cnt[*it]++; 
 
*/


#include <vector>
typedef vector<vector<int> > VVInt;
typedef vector<int> VInt;

VVInt twoSums(VInt vi, int target) {
    // bool exist[INT_MAX] = {false};
    // bool exist[target + 1] = {false};
    VVInt vvi;
    for (VInt::const_iterator it = vi.begin();
          it!=vi.end(); ++it) {
        exist[*it] = true;
    }

    for (VInt::const_iterator it = vi.begin();
          it!=vi.end(); ++it) {
        if(exist[sum - *it]){
            VInt vi;
            vi.push_back(*it);
            vi.push_back(sum - *it);
            vvi.push_back(vi);
        }
    }
    return vvi;
}
