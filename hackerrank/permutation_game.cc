#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


bool isSorted(vector<int>& v, vector<bool>& bits) {
    int prev = 0;
    for(int i = 0; i < v.size(); ++i) {
        if (bits[i] == true) continue;
        else if (v[i] < prev) return false;
        else prev = v[i];
    }
    return true;
}
bool isWinning(vector<int>& v, vector<bool>& bits) {
    if (isSorted(v, bits)) return false;
    for(int i = 0; i < v.size(); ++i) {
        if (!bits[i]) {
            bits[i] = true;
            if (!isWinning(v, bits)) return true;
            bits[i] = false;
        }
    }
    return false;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int T;
    cin>>T;
    for(int i = 0; i < T; ++i) {
        int N;
        cin >> N;
        vector<int> v(N, false);
        vector<bool> bits(N);
        for(int j = 0; j < N; ++j) {
            cin >> v[j];
        }
        
        cout << (isWinning(v, bits)? "Alice":"Bob") << endl;
    }    
    return 0;
}
