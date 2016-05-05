#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int strobogrammaticInRange(string low, string high) {
        vector<string> vs0;
        vs0.push_back("");
        tbl[0] = vs0;
        vector<string> vs1;
        vs1.push_back("0");
        vs1.push_back("1");
        vs1.push_back("8");
        tbl[1] = vs1;
        int m = low.size(); 
        int n = high.size();
        for(int i = 2; i <= n; ++i) {
            vector<string> vs;
            vector<string>& vs_prev = tbl[i-2];
            for(int j = 0; j < vs_prev.size(); ++j) {
                if (i!=n) {
                    string str0 = "0" + vs_prev[j] + "0";
                    vs.push_back(str0);
                }
                string str1 = "1" + vs_prev[j] + "1";
                string str6 = "6" + vs_prev[j] + "6";
                string str8 = "8" + vs_prev[j] + "8";
                string str9 = "9" + vs_prev[j] + "9";
                vs.push_back(str1);
                vs.push_back(str6);
                vs.push_back(str8);
                vs.push_back(str9);
            }
            sort(vs.begin(), vs.end());
            tbl[i] = vs;
        }
        int cntL = 0, cntH = 0, sum = 0; 
        if (n==m) {
            for(int i = 0; i < tbl[n].size(); ++i) {
                cout << tbl[n][i]<< endl;
                if (!isMore(tbl[n][i], high) && !isLess(tbl[m][i], low)) cntH++;
            }
        } else {
            for(int i = 0; i < tbl[m].size(); ++i) {
                if (!isLess(tbl[m][i], low)) cntL++;
            }
            if (n>m) {
                for(int i = 0; i < tbl[n].size(); ++i) {
                    if (!isMore(tbl[n][i], high)) cntH++;
                }
            }
        }
        
        vector<int> vcnt(n+1);
        vcnt[0] = 0;
        vcnt[1] = 3;
        vcnt[2] = 4;
        for(int i = 3; i <= n; ++i) {
            if (i%2) {
                vcnt[i] = pow(5, (i+1)/2-2)*4*3;
            } else {
                vcnt[i] = pow(5, (i+1)/2-1)*4;
            }
        }
        for(int j = m+1; j <= n-1; ++j) {
            sum += vcnt[j];
        }
        return sum+cntL+cntH;
    }
    bool isMore (string& a, string& b) {
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] ==b[i]) continue;
            if (a[i] < b[i]) return false;
            else return true;
        }
        return false;
    }
    bool isLess (string& a, string& b) {
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] ==b[i]) continue;
            if (a[i] < b[i]) return true;
            else return false;
        }
        return false;
    }
    map<int, vector<string> > tbl;
    int strobogrammaticInRange2(string low, string high) {
        vector<string> vs0;
        vs0.push_back("");
        vector<string> last = vs0;
        vector<string> vs1;
        vs1.push_back("0");
        vs1.push_back("1");
        vs1.push_back("8");
        vector<string> prev = vs1;
        int m = low.size(); 
        int n = high.size();
        vector<string> vm, vn;
        if (m == 0) vm = vs0;
        if (n == 0) vn = vs0;
        if (m == 1) vm = vs1;
        if (n == 1) vn = vs1;

        for(int i = 2; i <= n; ++i) {
            vector<string> vs;
            for(int j = 0; j < last.size(); ++j) {
                if (i!=n) {
                    string str0 = "0" + last[j] + "0";
                    vs.push_back(str0);
                }
                string str1 = "1" + last[j] + "1";
                string str6 = "6" + last[j] + "6";
                string str8 = "8" + last[j] + "8";
                string str9 = "9" + last[j] + "9";
                vs.push_back(str1);
                vs.push_back(str6);
                vs.push_back(str8);
                vs.push_back(str9);
            }
            sort(vs.begin(), vs.end());
            if (i==m) {
                vm = vs;
            } 
            if (i==n) {
                vn = vs;
            }
            last = prev;
            prev = vs;
        }
        
        int cntL = 0, cntH = 0, sum = 0; 
        if (n==m) {
            for(int i = 0; i < vn.size(); ++i) {
                if (!isMore(vn[i], high) && !isLess(vn[i], low)) cntH++;
            }
        } else {
            for(int i = 0; i < vm.size(); ++i) {
                if (!isLess(vm[i], low)) cntL++;
            }
            if (n>m) {
                for(int i = 0; i < vn.size(); ++i) {
                    if (!isMore(vn[i], high)) cntH++;
                }
            }
        }
        vector<int> vcnt(n+1);
        vcnt[0] = 0;
        vcnt[1] = 3;
        vcnt[2] = 4;
        for(int i = 3; i <= n; ++i) {
            if (i%2) {
                vcnt[i] = pow(5, (i+1)/2-2)*4*3;
            } else {
                vcnt[i] = pow(5, (i+1)/2-1)*4;
            }
        }
        for(int j = m+1; j <= n-1; ++j) {
            sum += vcnt[j];
        }
        return sum+cntL+cntH;
    }
};

int main() {
    Solution s;
    int i = s.strobogrammaticInRange2("11", "69");
    cout << i << endl;
}