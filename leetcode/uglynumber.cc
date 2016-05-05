#include <set>
#include <iostream>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        if(n== 0) return 0;
        if (n == 1) return 1;
        int last = 1;
        s.insert(1);
        while(s.size()<n) {
            if (isUgly(++last)) {
                s.insert(last);
            }
        }
        return last;
    }
    bool isUgly(int i){
        if (!(i%2)) {
            if (s.find(i/2) != s.end()) return true;
        } else if (!(i%3)) {
            if (s.find(i/3) != s.end()) return true;
        } else if(!(i%5)) {
            if (s.find(i/5) != s.end()) return true;
        }
        return false;
    }
    set<int> s;

};

int main(){
    Solution s;
    cout << s.nthUglyNumber(361) << endl;;
}