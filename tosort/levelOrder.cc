/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <queue>



class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!root) return NULL;
        q.push(root);


    }

    void doRecTra(TreeNode* node, int level){
      TreeNode* node = q.front();
      if(!node) {
        return;
      } else{

        q.pop();
        q.push(node->left());
        q.push(node->right());
      }



        }
    }

    queue<TreeNode*> q;
};
