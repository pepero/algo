/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        max = 0;
        doMaxTra(0, root);
        return max;
    }
    
    void doMaxTra(int depth, TreeNode *node){
        if(!node) {
            if(max<depth) {
                max = depth;
            }
        } else {
            doMaxTra(depth+1, node->left);
            doMaxTra(depth+1, node->right);
        }
    }
    int max;
};
