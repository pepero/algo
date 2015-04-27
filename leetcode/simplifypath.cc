/*
 * simplifypath.cc
 *
 *  Created on: Apr 27, 2015
 *      Author: shao
 */

#include <vector>
#include <string>
#include <sstream>
#include <iostream>  


using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> elems;
        std::stringstream ss(path);
        std::string item, str_ret;
        while (std::getline(ss, item, '/')) {
            elems.push_back(item);
        }

        while(!elems.empty() && *elems.begin() == "") elems.erase(elems.begin());

        for(vector<string>::iterator it = elems.begin();
            it!=elems.end();)
        {
            if (*it == "." || *it == ""){
                vector<string>::iterator it2 = it;
                elems.erase(it2);
            }
            else if (*it == ".."){
                vector<string>::iterator it2 = it;
                if(it2 != elems.begin()){
                    vector<string>::iterator it3 = it2;
                    elems.erase(it2);
                    it3--;
                    it = it3;
                    elems.erase(it3);
                } else{
                    elems.erase(it2);
                }
            } else{
                ++it;
            }
        }
        
        if(elems.empty()) return "/";

        for(vector<string>::iterator it = elems.begin();
            it!=elems.end(); ++it)
        {
            str_ret += "/" + *it;
        }
        return str_ret;
    }
};


int main(){
    Solution s;
    // cout << s.simplifyPath("/ws_root/.././././ws_root/path");
    cout << s.simplifyPath("/");

}

