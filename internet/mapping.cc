#include <iostream>
#include <list>
#include <map>

using namespace std;

typedef map<char, char> Table;
typedef list<string> StrList;
typedef list<string>::const_iterator ItList;
typedef string::iterator ItStr;

class Solution {
public:
    Table findTable(StrList strList1, StrList strList2){
        Table table;
        for(ItList it1=strList1.begin(), it2=strList2.begin();
            it1 != strList1.end(), it2 != strList2.end(); ++it1, ++it2) {
            string str1 = *it1;
            string str2 = *it2;
            for(ItStr itstr1 = str1.begin(), itstr2 = str2.begin();
                 itstr1 != str1.end(), itstr2 != str2.end(); ++itstr1, ++itstr2) {
                table[*itstr1] = *itstr2;
            }
        }
        return table;
    }
};

int main()
{
    Table table;
    StrList strList1;
    strList1.push_back("cat");
    strList1.push_back("coffee");
    strList1.push_back("common");

    // StrList strList2.push_back("dkc");
    StrList strList2;
    strList2.push_back("dkc");
    strList2.push_back("dbhhzz");
    strList2.push_back("dbllbq");
    Solution s;
    table = s.findTable(strList1, strList2);
    for(Table::const_iterator it=table.begin();it!=table.end();++it) {
        cout << it->first << "->" << it->second <<endl;
    }
}




