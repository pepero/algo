#include <iostream>
using namespace std;

int findCycle(int idx[], int size){
	bool visited[size] = {false};
	int max = 1;
	for (int i = 0; i < size; ++i) {
		if (!visited[i]) {
			visited[j] = true;
			int cnt = 1;
			for (int j = idx[i]; j!=i; j = idx[j]) {
					visited[j] = true;
					if (cnt > max) max = cnt;
			}
		}
	}
	return max;
}

int main(){
	int idx [] = {3 2 1 4 0};
 	cout << findCycle (idx, 5) << endl;
}
