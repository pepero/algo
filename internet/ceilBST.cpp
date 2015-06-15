#include <iostream>
#include <climits>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val){
      val = val;
      left = NULL;
      right = NULL;}
};

class Solution {
public:
    int findCeilBST(TreeNode* root, int val){
      min = INT_MIN;
      findCeilRec(root, val);
      return min;
    }
    void findCeilRec(TreeNode* node, int val){
      if(!node) return;
      if (node->val > val) findCeilRec(node->left, val);
      if (node->val <= val) {
        if (min < node->val) {
          min = node->val;}
        findCeilRec (node->right, val);
      }
    }

//    TreeNode* insertBST(TreeNode* root, int val){
//      if(!root) return new TreeNode(val);
//      else{
//        if (root->val >= val) insertBST(root->left, val);
//        else insertBST(root->right, val);
//      }
//      return root;
//    }

//    void insertBST(TreeNode* root, int val){
//      if(!root) root = new TreeNode(val);
//      if (root->val >= val) insertBST(root->left, val);
//      if (root->val < val) insertBST(root->right, val);
//    }

    void insertBST(TreeNode*& root, int val){
      if(!root) root = new TreeNode(val);
      else if (root->val > val) insertBST(root->left, val);
      else insertBST(root->right, val);
    }

    int min;
};

int main(){

    Solution s;
    int ints[]={4, 2, 1};
		TreeNode* root = NULL;
    for (int i=0; i<3; i++){
      s.insertBST(root, ints[i]);
    }

    int i = s.findCeilBST(root, 8);
    cout << "ceil is" << i <<endl;
}
