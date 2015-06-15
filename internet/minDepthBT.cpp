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
    int minDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        min = INT_MAX;
        if (!root) return 0;
        doMinDepth(root, 1);
        return min;
    }
    
    void doMinDepth(TreeNode* node, int depth){
        if(!node->left && !node->right){
            if (depth < min) min = depth;
        } 
        else{
            if (node->left) doMinDepth(node->left, depth+1);
            if (node->right) doMinDepth(node->right, depth+1);
        }
    }
    int min;
};
