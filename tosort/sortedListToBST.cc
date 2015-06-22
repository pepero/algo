#include<iostream>

using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
  };
 
/**
 * Definition for binary tree
 */
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    TreeNode* sortedListToBST(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!head) return NULL;
        int endIdx = 0;
        ListNode* endNode = findEnd(head, endIdx);
        return recurToBST(head, endNode, 0, endIdx);             
    }

    TreeNode* recurToBST(ListNode *head, ListNode *end, int begin, int end_idx){
        TreeNode* node = NULL;
        if(begin == end_idx){
                    node = new TreeNode(head->val);
            }
            if(begin == end_idx - 1){
                    node = new TreeNode(head->val);
                    node->left =  NULL;
                    node->right = new TreeNode(end->val);
            }
            if(begin < end_idx - 1){
                    int mid_idx = (begin + end_idx) / 2 ;
                    ListNode* mid_bef = findMid(begin, mid_idx, head);
                    ListNode* mid = mid_bef->next;
                    ListNode* mid_aft = mid->next;
                    node = new TreeNode(mid->val);
                    node->left = recurToBST(head, mid_bef, begin, mid_idx-1);
                    node->right = recurToBST(mid_aft, end, mid_idx+1, end_idx);
            }
            return node;           
        }
       
        // the relative postion
//      ListNode* findMid(int mid, ListNode* head){
//              for(int i=0; i<mid-1; i++) head = head->next;
//              return head;
//      }
        ListNode* findMid(int start, int mid, ListNode* head){
                for(int i=start; i<mid-1; i++) head = head->next;
                return head;
        }
       
        ListNode* findEnd(ListNode* head, int& end_idx){
          if(!head){ end_idx = 0; return NULL; }
                while((head->next)) {
                  end_idx++;
                  head = head->next; }
                return head;
        }
};


class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int size = 0;
        while (head) {
            size++;
            head = head->next;
        }
        recursiveBuild(0, size);
        
    }
    
    TreeNode *recursiveBuild(int begin, int end) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(begin == end) return new TreeNode(getNext());
        int mid = (begin+end) / 2;
        TreeNode* nodeL= recursiveBuild(begin, mid -1);
        TreeNode* parentNode = new TreeNode(getNext());
        parentNode->left=nodeL;
        TreeNode* nodeR= recursiveBuild(mid+1, end);
        parentNode->right=nodeR;
    }
    
    int getNext(){
        int j = nodeIter->val;
        nodeIter = nodeIter->next;
        return j;
    }
    static ListNode* nodeIter = head;

};

void preOderTree(TreeNode* node)
{
    if(!node)  return;
        cout << node->val << endl;
        preOderTree(node->left);
        preOderTree(node->right);
}

ListNode* buildList()
{
    ListNode* head = NULL;
    ListNode* node = NULL;
    for(int i=0; i<6; i++) {
        if(!head) {
            head = new ListNode(i); 
            node = head;
        } else{
             node->next = new ListNode(i); 
             node = node->next;
        }
    }
    return head;
}

int main()
{
    ListNode* head = buildList();
    Solution s;
    TreeNode* root = s.sortedListToBST(head);
    preOderTree(root);
   
}
