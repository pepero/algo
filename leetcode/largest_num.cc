#include <string>
#include <vector>
#include <iostream>
#include <map>


using namespace std;

struct MyCustomFunctor
{
    bool operator()(const string& a, const string& b) { 
        int mini = min (a.length(), b.length());
        for(int i=0; i < mini; ++i){
            if (a[i] < b[i])
            return true;
        }
        if (a.length() == b.length()) return false;
        if (a.length() < b.length()) {
            if (b[mini] > a[0]) return false;
            else return true;
        }
        if (a.length() > b.length()) {
            if (a[mini] > b[0]) return false;
            else return true;
        }
        return true;

    }
};

typedef map<string, int, MyCustomFunctor> Table;

string largestNumber(vector<int> &num) {
    Table tbl;
    for(int i=0; i< num.size(); ++i){
        string str = to_string((long long) num[i]);
        Table::iterator it = tbl.find(str);
        if (it==tbl.end()){
            tbl.insert(make_pair(str, 1));   
        } else{
            it->second = it->second + 1;
        }
    }
    string ret;
    for(Table::reverse_iterator it = tbl.rbegin(); 
        it != tbl.rend(); ++it){
        for(int i = 0; i < it->second; ++i){
            ret += it->first;
        }
    }
    return ret;
}

int main(){
    vector<int> ints ={3, 30, 34, 5, 9};

    cout << largestNumber(ints) << endl;
}
