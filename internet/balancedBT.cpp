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
        v.clear();
        if(!root) return true;
        doFindDepth(root, 1);
        int max = *max_element(std::begin(v), std::end(v));
        int min = *min_element(std::begin(v), std::end(v));
        if (max>min+1) return false;
        else return true;        
    }
    void doFindDepth(TreeNode *node, int i){
        if(!node->left && !node->right){
            v.push_back(i);          
        } else {
            if(node->left) doFindDepth(node->left, i+1);
            if(node->right) doFindDepth(node->right, i+1);
        }
    }
    vector<int> v;
};
