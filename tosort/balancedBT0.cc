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
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!root) { return true; }
        return getHeight(root)>=0;
        
    }
    
    int getHeight(TreeNode* node){
        if(!node) { return 0; }
        int l = getHeight(node->left);
        int r = getHeight(node->right);
        if(l==-1 || r ==-1 || abs(l-r)>1) {
            return -1;
        }
        return max(l, r)+1;
    }
};
