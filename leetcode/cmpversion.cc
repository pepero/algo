#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int compareVersion(string version1, string version2) {
    stringstream ss1(version1);
    stringstream ss2(version2);
    string word1, word2;
    while (true){
        int i = 0, j = 0;
        bool s1f = false, s2f = false;
        if (getline(ss1, word1, '.')) {
            stringstream sw1(word1);
            sw1 >> i;
        } else {
            s1f = true;
        }

        if (getline(ss2, word2, '.') {
            stringstream sw2(word2);
            sw2 >> j;
        } else {
            s2f = true;
        }
        if(i > j) return 1;
        if(i < j) return -1;
        if (!s1f && !s2f) return 0;
    }
}

int main(){
    compareVersion("1.0", "1.1");
}
