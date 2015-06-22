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
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        TreeNode* mirrNode = buildMirrBT(root);
        return binaryTreeCompare(root, mirrNode);      
    }
    
    TreeNode* buildMirrBT(TreeNode* root) {
        if (!root) return NULL;
        TreeNode* node = new TreeNode(root->val);
        node->left = buildMirrBT(root->right);
        node->right = buildMirrBT(root->left);
        return node;
    }
    
    bool binaryTreeCompare(TreeNode *a,TreeNode *b) {
        if (!a && !b) return true;
        if ((!a && b) || (!b && a)) return false;
        return ((a->val == b->val) 
                &&  
                binaryTreeCompare(a->left, b->left)
                && 
                binaryTreeCompare(a->right, b->right));
        
    }
};
