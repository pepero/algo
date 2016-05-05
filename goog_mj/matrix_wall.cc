/*
第二轮白人小妹儿 听起来感觉特热情。。。
一上来问我recent project 我去。。。不是gg都是一上来直接做题的吗。。。蒙圈儿三秒之后 cc大法好。。。
然后做题 面完也没找到这个题 我简单描述一下。。。
一个N*N matrix 每一个点由如下class表示. 鐗涗汉浜戦泦,涓€浜╀笁鍒嗗湴
class Point{
    int x;
    int y;
}
对于matrix里的点 要么可以站在上面loop up/down/left/right 要么就是wall或者light wall可以挡住lights
比如
L*LQ*W
*L****
W*LL**
L*L**W
*L****
W*LL**

比如站在这个Q点 可以看到4个lights(左边两个下面两个)
要求找到这个matrix里面可以看到最多lights的Point 并且return it
input是walls, lights, N (walls和lights是List<Point>)
output是Point

then 时间复杂度空间复杂度

*/
#include <vector>
#include <map>
#include <iostream>
using namespace std;
int maxLen (vector<vector<int> >& matrix) {
	int m = matrix.size();
	if (m == 0) return 0;
	int maxv = 0;
	int prev, next = 0;
	int n = matrix[0].size();
	map<int, int> tbl;
	for(int i = 0; i <m; ++i) {
		prev = matrix[i][0] == 'L' ? 1 : 0;
		for(int j = 1; j < n; ++j) {
			if (matrix[i][j] == 'W'){
				next = 0;
			} else {
				next = prev+ (matrix[i][j] == 'L' ? 1: 0);
				if (matrix[i][j]== '*') {
					tbl[n*i+j] +=next;
				}
			}
			prev = next;
		}
		prev = matrix[i][n-1] == 'L' ? 1 : 0;
		for(int j = n-2; j >= 0; --j) {
			if (matrix[i][j] == 'W'){
				next = 0;
			} else {
				next = prev+ (matrix[i][j] == 'L' ? 1: 0);
				if (matrix[i][j]== '*') {
					tbl[n*i+j] +=next;
				}
			}
			prev = next;
		}
	}
	for(int j = 0; j <n; ++j) {
		prev = matrix[0][j] == 'L' ? 1 : 0;
		for(int i = 1; i < m; ++i) {
			if (matrix[i][j] == 'W'){
				next = 0;
			} else {
				next = prev+ (matrix[i][j] == 'L' ? 1: 0);
				if (matrix[i][j]== '*') {
					tbl[n*i+j] +=next;
				}
			}
			prev = next;
		}
		prev = matrix[m-1][0] == 'L' ? 1 : 0;
		for(int i = m-2; i >= 0; --i) {
			if (matrix[i][j] == 'W'){
				next = 0;
			} else {
				next = prev+ (matrix[i][j] == 'L' ? 1: 0);
				if (matrix[i][j]== '*') {
					tbl[n*i+j] +=next;
					maxv = max(maxv, tbl[n*i+j]);
				}
			}
			prev = next;
		}
	}
	return maxv;
}

int main(){
	int a[6][6] = {	  {'L', '*', 'L', '*', '*', 'W'}, 
		              {'*', 'L', '*', '*', '*', '*'}, 
		              {'W', '*', 'L', 'L', '*', '*'}, 
		              {'L', '*', 'L', '*', '*', 'W'}, 
		              {'*', 'L', '*', '*', '*', '*'}, 
		              {'W', '*', 'L', 'L', '*', '*'}
				};
	vector<vector<int> > vvi (6, vector<int>(6));
	for(int i= 0; i < 6; ++i) {
		vvi[i].assign(a[i], a[i]+6);
	}
	cout << maxLen(vvi) << endl;
}