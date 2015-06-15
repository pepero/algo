/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include "stdio.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!root) return true;
        bool isValid = isValidBST(root->left);
        if (isValid && (root->val > indexVal)){
            indexVal = root->val;                        
        }else { isValid = false; }
        if(isValid){
            isValid = isValidBST(root->right);
        }
        return isValid; 
    }

    bool createFromArray(int a[], int size)
    {
        for(int i=0; i<size; i++) {
            buildBST(i, root);
        }
    }

    void buildBST(int i, TreeNode* node)
    {
        if(!node) {
            node = new TreeNode(i);
        }
        else{
            if(node->val >= i) {
                if(!node->left) {
                    TreeNode* node = new TreeNode(i);
                    node->left = node;
                }
                else{
                    buildBST(i, node->left);
                }
            }
            else{
                if(!node->right) {
                    TreeNode* node = new TreeNode(i);
                    node->right = node;
                }
                else{
                    buildBST(i, node->right);
                }
            }
        }
    }
    TreeNode* root;
    int indexVal;
};

int main()
{
    int a[5]={0, 1, 2, 3, 4};
    Solution sol;
    sol.root = NULL;
    sol.createFromArray(a, 5);
    if(sol.isValidBST(sol.root))
    {
        printf("valid bst \n");
    }
}
