#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return NULL;
        if (!root->left && !root->right) return root;
        TreeNode * inl = invertTree(root->left);
        TreeNode* inr = invertTree(root->right);
        root->left = inr;
        root->right = inl;
        return root;
    }
};

int main(){
	Solution s;
	TreeNode root(1), left(2), right (3);
	root.left = &left;
	root.right = &right;
	s.invertTree(&root);
	cout << root.val;
	cout << root.left->val;
	cout << root.right->val;
}
