#include <iostream>
#include <list>

using namespace std;

typedef list<int> ListInt;
typedef list<int>::const_iterator It;


class Solution {
public:
//  list<int> intersect_to_check(list<int> intList1, list<int> intList2){
//      int pos1 = 0;
//      int pos2 = 0;
//      list<int> intList3;
//
//      while(pos1 < intList1.size() && pos2 < intList2.size()) {
//          if (intList1[pos1] == intList1[pos2]) {
//              intList3.push(intList1[pos1]);
//              pos1++;
//              pos2++;
//          } else if (intList1[pos1] < intList1[pos2]) {
//              pos1++;
//          } else {
//              pos2++;
//          }
//      }
//      return intList3;
//  }

//  list<int> intersect_iteratr(list<int> intList1, list<int> intList2){
//      list<int>::const_iterator it1;
//      list<int>::const_iterator it2;
//      list<int> intList3;
//
//      while(it1 ! = intList1.end() && it2 != intList2.end()) {
//          if (*it1 == *it2) {
//              intList3.push(intList1[pos1]);
//              ++it1;
//              ++it2;
//          } else if (*it1 < *it2) {
//              ++it1;
//          } else {
//              ++it2;
//          }
//      }
//      return intList3;
//  }

    ListInt intersect(ListInt intList1, ListInt intList2){
        It it1 = intList1.begin();
        It it2 = intList2.begin();
        ListInt intList3;

        while((it1 != intList1.end()) && (it2 != intList2.end())) {
            if (*it1 == *it2) {
                intList3.push_back(*it1);
                ++it1;
                ++it2;
            } else if (*it1 < *it2) {
                ++it1;
            } else {
                ++it2;
            }
        }
        return intList3;
    }
};

int main()
{
    int ints1[] = {5, 6, 6, 8};
    int ints2[] = {4, 4, 6, 6, 8};
    ListInt list1 (ints1, ints1 + 4 );
    ListInt list2 (ints2, ints2 + sizeof(ints2) / sizeof(int) );
    Solution s;
    ListInt list3 = s.intersect(list1, list2);
    for(It it=list3.begin(); it!=list3.end(); ++it) {
        cout << *it << endl;
    }
}




