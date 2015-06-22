#include <boost/unordered_map.hpp>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;


class Solution {
public:
//  // ascii
    bool strSetAsci(string str, string target){
        bool exist[256] = {false};
        for (int i = 0; i < target.size(); i++) {
            exist[target.at(i)] = true;
        }

        for (int i = 0; i < str.size(); i++) {
            if (exist[str.at(i)]) return true;
        }
    }

    // unicode
    bool strSet(char* str, char* target){
        boost::unordered_map<string, bool> hashtbl;
        int nBytes = 0;
        for (int i = 0; i < sizeof(target); i+=nBytes) {
            char first = *(target+i);
            nBytes = clz(~first); 
            char text [nBytes];
            memcpy(text, target +i, nBytes);
            string str1(text);          
            hashtbl[str1] = true;         
        }

        for (int i = 0; i < sizeof(target); i+=nBytes) {
            char first = *(str+i);
            nBytes = clz(~first);
            char text [nBytes];
            memcpy(text, str +i, nBytes);
            string str1(text);          
            hashtbl[str1] = true;         
        }
    }

    int clz(char c){
        if (c==0) return 8;
        int cnt = 0;
        if(c < 0x0f) {
            cnt +=4;
            c << 4;
        }
        if(c < 0x3f) {
            cnt +=2;
            c << 2;
        }
        if(c < 0x1f) {
            cnt +=1;
            c << 1;
        }
        return cnt; 
    }
};

int main(){

    Solution s;
    if (s.strSet("\uFF0E", "¤")) cout << "found" <<endl;

}
