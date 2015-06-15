#include <vector>
#include <iostream>
using namespace std;
typedef vector<vector<int> > VVInt;
typedef vector<int> VInt;

class Solution{
public:
	bool searchMatrix(vector<vector<int> > &matrix, int target){
		found = false;
		int rows = matrix.size();
		int idx = biVertical(matrix, 0, rows-1, target);
		int size = matrix[idx].size();
		if (!found) {
			biHorizontal(matrix[idx], 0, size-1, target);
		}
		return found;	
	}
	int biVertical(VVInt &vvi, int start, int end, int target){
    	if (start > end) return end;
    	int mid = start + (end-start)/2;
    	if (vvi[mid][0] == target) {
    		found = true; 
    		return mid;
    	} else if (vvi[mid][0] > target) {
    		return biVertical(vvi, start, mid-1, target);
    	} else {
    		return biVertical(vvi, mid+1, end, target);
    	}
    }

    int biHorizontal(VInt &vi, int start, int end, int target){
    	if (start > end) return end;
    	int mid = start + (end-start)/2;
    	if (vi[mid] == target) {
    		found = true; 
    		return mid;
    	} else if (vi[mid] > target) {
    		return biHorizontal(vi, start, mid-1, target);
    	} else {
    		return biHorizontal(vi, mid+1, end, target);
    	}
    }
	bool found;
};

int main(){
	int x1[] = {1,2,3,4};
	int x2[] = {5, 6, 7, 8};

	int x3[] = {1,1};
	// VInt v1 (x1, x1 + sizeof x1 / sizeof x1[0]);
	// VInt v2 (x2, x2 + sizeof x2 / sizeof x2[0]);
	VInt v3 (x3, x3 + sizeof x3 / sizeof x3[0]);
	VVInt vvi;
	vvi.push_back(v3);
	// vvi.push_back(v2);

	Solution s;
	if (s.searchMatrix(vvi, 0))
		cout << "found" << endl;

}
