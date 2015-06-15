#include <iostream>
using namespace std;

class Solution {
public:
    double pow(double x, int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (n == 0) return 1;
        int i = pow(x, n/2);
        if (n%2!=0) return i*i*x;
        else return i*i;
    }
};

int main()
{
    Solution s;
    cout << s.pow(8.88023, 3) << endl;
}
