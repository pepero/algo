#include <vector>
#include <list>

using namespace std;

class Solution {
public:
    list<int> intersect(list<int> intList1, list<int> intList2){
        int pos1 = 0;
        int pos2 = 0;
        list<int> intList3;
        while(pos1 < intList1.size() && pos2 < intList2.size()) {
            if (intList1[pos1] == intList1[pos2]) {
                intList3.push(intList1[pos1]);
                pos1++;
                pos2++;
            } else if (intList1[pos1] < intList1[pos2]) {
                pos1++;
            } else {
                pos2++;
            }
        }
        return intList3;
    }    
};

int main()
{
    int ints1[] = {5, 6, 6, 8};
    int ints2[] = {4, 4, 6, 6, 8};
    list<int> list1 (ints1, ints1 + sizeof(ints1) / sizeof(int) );
    list<int> list2 (ints2, ints2 + sizeof(ints2) / sizeof(int) );
    list<int> list3 = intersect(list1, list2);
    for(list<int>::const_iterator it=list3.begin(); it!=list3.end(); ++it) {
        cout << *it << endl;
    }
}




