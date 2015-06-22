#include<iostream>
#include<set>
#include<string>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        set<int> lut;
        ListNode* node = head;
        if (!node) return NULL;
        else lut.insert(node->val);
        
        while(node->next){
            if (lut.find(node->next->val)==lut.end()){
                lut.insert(node->next->val);
                node = node->next;
            } else{
                node->next = node->next->next;
            }
        }
        return head;
    }
};
int main(){
    int ints[] = {1,2,3,4,5,4};
    ListNode* head = NULL;
    ListNode* node = NULL;
    for (int i = 0; i < 6; i++) {
        if (!head) {
            head = new ListNode(ints[i]);
            node = head;
        }        
        else {
            node->next = new ListNode(ints[i]);
            node = node->next;
        }
    }

    Solution s;
    s.deleteDuplicates(head);
}




