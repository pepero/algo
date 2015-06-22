/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
#include <cstddef>

struct TreeLinkNode {
   int val;
   TreeLinkNode *left, *right, *next;
   TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
  };

class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (!root) return;
        root->next = NULL;
        TreeLinkNode* nodeParent = root;
        TreeLinkNode* nodeChildFirst = NULL;
        TreeLinkNode* nodeChildIter = NULL;
        while(nodeParent){
            if(nodeParent->left) {
                if(!nodeChildFirst) {
                    nodeChildFirst = nodeParent->left;
                    nodeChildIter = nodeParent->left;
                } else{
                    nodeChildIter->next = nodeParent->left;
                    nodeChildIter = nodeChildIter->next;
                }
            }
            if(nodeParent->right) {
                if(!nodeChildFirst) {
                    nodeChildFirst = nodeParent->right;
                    nodeChildIter = nodeParent->right;
                } else{
                    nodeChildIter->next = nodeParent->right;
                    nodeChildIter = nodeChildIter->next;
                }
            }
            nodeParent = nodeParent->next;
            if (!nodeParent) {
                if(nodeChildFirst) {
                    nodeParent = nodeChildFirst;
                    nodeChildIter->next = NULL;
                    nodeChildFirst = NULL;
                    nodeChildIter = NULL;
                } else break;       
            }
        }
    }
};

int main(){
    Solution s;
    TreeLinkNode node(0);
    TreeLinkNode node1(1);
    TreeLinkNode node2(2);
    node.left = &node1;
    node.right = &node2;
    s.connect(&node);
}
