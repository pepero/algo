#include <map>
#include <set>
#include <algorithm>
using namespace std;

class LRUCache{
public:
    LRUCache(int capacity) {
        m_capacity = capacity;
    }
    
    int get(int key) {
        map<int, int>::iterator it;
        it1 = tbl1.find(key);
        if (it1!=tbl1.end()) {
            int cnt = it1->second.second++;
            tbl2[cnt-1].erase(key);
            tbl2[cnt].insert(key);
            return it1->second.first;
        } else {
            return -1;
        }
    }
    
    void set(int key, int value) {
        map<int, int>::iterator it;
        it = tbl1.find(key);
        if (it!=tbl1.end()) {
            it->second = value;
            int cnt = it->second.second++;
            tbl2[cnt-1].erase(key);
            tbl2[cnt].insert(key);
        } else {
            if (tbl1.size() == m_capacity) {
                it = tbl2.begin();
                int k = *it->second.begin();
                it->second.erase(it->second.begin());
                tbl1.erase(k);
            } 
            tbl1[key] = make_pair(value, 1);
            tbl2[1].insert(key);
        }
    }
    map<int, pair<int, int> > tbl1;
    map<int, set<int> > tbl2;
    int m_capacity;
};

int main(){
    Solution s;
}

