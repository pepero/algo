#include <iostream>
#include <sstream>
using namespace std;

int main(){
    string str = "abc xyz";  
//  stringstream ss(str);
//  cout << ss.str() <<endl;  // "abc xyz"
//
//  ss >> str;
//  cout << ss.str() <<endl; // "abc xyz"
//  cout << ss.tellp() << endl;
//  ss << str;
//  cout << ss.tellp() << endl;
//  cout << ss.str() <<endl;
//  ss >> str;
   
    stringstream ss(str);

    cout << ss.tellp() << endl;
    cout << ss.tellg() << endl;
    ss >> str;
    cout << ss.tellp() << endl;
    cout << ss.tellg() << endl;

    ss << str;
    cout << ss.tellp() << endl;
    cout << ss.tellg() << endl;

    ss >> str;
    // ss >> std::noskipws >> str; fails, why??
    cout << ss.tellp() << endl;
    cout << ss.tellg() << endl;

    if (!ss.good()) {
        std::cout << " good()=" << ss.good();
        std::cout << " eof()=" << ss.eof();
        std::cout << " fail()=" << ss.fail();
        std::cout << " bad()=" << ss.bad();
    }
    cout << str <<endl;  //"xyz"
}


