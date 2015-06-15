class Solution {
public:
    bool createFromArray(int a[], int size)
    {
        for(int i=0; i<size; i++) {
            insertBST(i, root);
        }
    }

    void insertBST(int i, TreeNode* node)
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
                    insertBST(i, node->left);
                }
            }
            else{
                if(!node->right) {
                    TreeNode* node = new TreeNode(i);
                    node->right = node;
                }
                else{
                    insertBST(i, node->right);
                }
            }
        }
    }

		

    TreeNode* root;
};
