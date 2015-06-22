#include<iostream>
#include<sstream>
#include<string>

using namespace std;

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        recSearch(A, 0, n-1, target);
    }

        
    int recSearch1(int a[], int begin, int end, int target){
        if(begin > end) return end;
        int mid = begin + (end - begin)/2;
        if (a[mid] == target) return mid;
        if (a[mid] < target) return recSearch(a, mid+1, end, target);
        else return recSearch(a, begin, mid-1, target);
    }
    
    int recSearch2(int a[], int begin, int end, int target){
        int mid = begin + (end - begin)/2;
        if (a[mid] == target) return mid;
        if (a[mid] < target) {
            if (mid+1 < end) {
                return recSearch(a, mid+1, end, target);
            } else return mid+1;
        } else {
            if (begin < mid-1) {
                return recSearch(a, begin, mid-1, target);
            } else return mid-1;
        }
    }

    int recSearch3_ac(int a[], int begin, int end, int target){
        int mid = begin + (end - begin)/2;
        if (a[mid] == target) return mid;
        if (a[mid] < target) {
            if (mid+1 <= end) {
                return recSearch(a, mid+1, end, target);
            } else return mid + 1;
        } else {
            if (begin <= mid-1) {
                return recSearch(a, begin, mid-1, target);
            } else return begin;
        }
    }

    int recSearch4_ac(int a[], int begin, int end, int target){
        if(begin > end) return begin;
        int mid = begin + (end - begin)/2;
        if (a[mid] == target) return mid;
        if (a[mid] < target) return recSearch(a, mid+1, end, target);
        else return recSearch(a, begin, mid-1, target);
    }

		int recSearch5(int a[], int begin, int end, int target){
    		if(begin <= end) {
		      int mid = begin + (end - begin)/2;
		      if (a[mid] == target) return mid;
		      if (a[mid] < target) return recSearch(a, mid+1, end, target);
		      else return recSearch(a, begin, mid-1, target);
			} else return begin;
    }

};

int main(){
    Solution s;
}

// 1. -7 % 3 = -1
// 2. 7 % -3 = 1;
// 3. catch int overflow
// in-place


