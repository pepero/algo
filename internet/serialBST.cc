#include <iostream>
#include <vector>
#include <climits>

using namespace std;

typedef vector<int> VecInt;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(VecInt vi){
        static int i = 0;
        if(vi.empty()) { return NULL;}
        TreeNode* root = new TreeNode(vi[i]);
        i++;
        preOrder(root, INT_MAX);
        return root;
    }

    void preOrder(TreeNode* parent, int gp){
        // left child
        if(vi[i] < parent->val) {
            parent->left = new TreeNode(vi[i]);
            i++;
            preOrder(parent->left, parent->val);
        }
        // right child
        if(parent->val < vi[i] && vi[i] <  gp) {
            parent->right = new TreeNode(vi[i]);
            i++;
            preOrder(parent->right, parent->val);
        }  
    }


    TreeNode* buildTree2(){
        if(vi.empty()) { return NULL;}
        return preOrder2(INT_MAX, INT_MAX);
    }

    TreeNode* preOrder2(int p, int gp){
        TreeNode* node = NULL;
        if((vi[i] < p) || (p < vi[i] && vi[i] < gp)) {
            node = new TreeNode(vi[i]);
            i++;
            node->left = preOrder2(node->val, p);            
            node->right = preOrder2(node->val, p);
            
        }        
        return node;
    }
    int i;
    VecInt vi;
};

void preOrderTree(TreeNode* node)
{
	if(!node) { return;};
		cout << node->val << endl;
		preOrderTree(node->left);
		preOrderTree(node->right);
}

int main()
{
   int ints1[]= {4, 2, 1, 3, 6, 5, 7};
   int ints2[]= {4, 3, 2, 1, 5, 6, 7};
   VecInt vi1(ints1, ints1 + sizeof ints1 / sizeof (int)); 
   VecInt vi2(ints2, ints2 + sizeof ints2 / sizeof (int)); 
   Solution s;
   s.vi = vi1;
   s.i = 0;
   preOrderTree(s.buildTree2());
}

  




