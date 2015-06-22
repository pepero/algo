
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        ListNode* result = NULL, node = NULL;
        ListNode* n1 = l1, n2 = l2;
        int i1 = 0, i2 = 0, i = 0, incr = 0;
        while (n1 || n2) {
          if (!n1) {
            i1 = 0;
          } else {
            i1 = n1->val;
          }
          if (!n2) {
            i2 = 0;
          } else {
            i2 = n2->val;
          }
          incr = (i1 + i2 + incr) / 10;
          i =  (i1 + i2 + incr) % 10;
          if (!result) {
            result = new ListNode(i);
            node = result;
          } else {
            node->next = new ListNode(i);
            node = node->next;
          }
          if (n1) {
            n1 = n1->next;
          }
          if (n2) {
            n2 = n2->next;;
          }
        }
        if (incr == 1) {
          node->next = new ListNode(1);          
        }
        node->next = NULL;
    }

    ListNode *addTwoNumbers2(ListNode *l1, ListNode *l2) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        ListNode* result = NULL, node = NULL, n3 = NULL;
        ListNode* n1 = l1, n2 = l2;
        int i1 = 0, i2 = 0, i = 0, incr = 0;
        while (n1 && n2) {
          incr = (n1->val + n2->val + incr) / 10;
          i =  (n1->val + n2->val + incr) % 10;
          if (!result) {
            result = new ListNode(i);
            node = result;
          } else {
            node->next = new ListNode(i);
            node = node->next;
          }
          n1 = n1->next;
          n2 = n2->next;
        }
        if (!n1 && n2) {
          ListNode n3 = n2;
        }
        if (!n1 && n2) {
          n3 = n2;
        }
        if (n1 && !n2) {
          n3 = n1;     
        }
        while(n3) {
          incr = (n3->val + incr) /10;
          i =  (n3->val + incr) % 10;
          if (!result) {
            result = new ListNode(i);
            node = result;
          } else {
            node->next = new ListNode(i);
            node = node->next;
          }
          n3 = n3->next;
        }
        if (incr == 1) {
          node->next = new ListNode(1);          
        }
        node->next = NULL;
    }

    ListNode *addTwoNumbers3(ListNode *l1, ListNode *l2) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        ListNode* result = NULL, node = NULL;
        ListNode* n1 = l1, n2 = l2;
        int sum = 0, carry = 0;
        while (n1 || n2 || carry) {
          sum = carry;
          if (n1) {
            sum += n1->val;
            n1 = n1->next;
          }
          if (n2) {
            sum += n2->val;
            n2 = n2->next;
          }      
          carry = sum / 10;
          if (!result) {
            result = new ListNode(sum % 10);
            node = result;
          } else {
            node->next = new ListNode(sum % 10);
            node = node->next;
          }
        }
        node->next = NULL;
    }
};
