#include <vector>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<ListNode*> v;
        ListNode* node = head;
        while(node){
            v.push_back(node);
            node = node->next;
        }
        int size = v.size();
        if (size > 0) {
            int pos = k%size;
            if (pos > 0) {
                ListNode* prev = v[size-1-pos];
                prev->next = NULL;
                v[size-1]->next = head;
                head = v[size-pos];
            }
        }
        return head;
    }
};

int main(){
    int ints[]= {0, 1,2, 3, 4, 5};
    ListNode* head = NULL;
    ListNode* node = NULL;
    for(int i=0; i<6; i++) {
        if(!head) {
            head = new ListNode(ints[i]);
            node = head;
        } else{
             node->next = new ListNode(ints[i]);
             node = node->next;
        }
    }
    Solution s;
    s.rotateRight(head, 2);
}
