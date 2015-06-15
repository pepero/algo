#include <vector>
#include <stddef.h>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
typedef vector <int> vecti;
class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        vecti vi;
        vt.clear();
        for (int i = 1; i <=n; ++i) vi.push_back(i);
        rec(NULL, vi);
        return vt;
    }
   
    void rec(TreeNode *sofar, vector <int> &vi) {
        if (vi.empty()){
            vt.push_back(recCopyTree(sofar));
            return;
        }
        for(int i = 0; i < vi.size(); ++i){
            sofar = insert(sofar, vi[i]);
            vecti vi_next = vi;
            vi_next.erase(vi_next.begin()+i);
            rec(sofar, vi_next);
            sofar = del(sofar, vi[i]);
        }
    }
    TreeNode* recCopyTree(TreeNode *src){
        TreeNode* root = NULL;
        if (src!=NULL){
            root = new TreeNode(src->val);
            root->left = recCopyTree(src->left);
            root->right = recCopyTree(src->right);
        }
        return root;
    }
    TreeNode* insert(TreeNode *root, int val){
        if (root==NULL){
            root = new TreeNode(val);
            return root;
        } 
        if (val > root->val) {
            root->right = insert(root->right, val); 
            return root;
        }
        if (val < root->val){
            root->left = insert(root->left, val);
            return root;
        }
    }
    TreeNode* findMin(TreeNode *root){
        if (!root) return NULL;
        while (root->left){
            root = root->left;
        }
        return root;
    }

    TreeNode* del(TreeNode *root, int val){
        if (!root) return NULL;
        if (val == root->val) {
            if (!root->left && !root->right) {
                delete root;
                return NULL;
            }
            if (!root->left) {
                TreeNode* temp = root;
                root = root->right;
                delete temp;
                return root;
            }
            if (!root->right) {
                TreeNode* temp = root;
                root = root->left;
                delete temp;
                return root;
            }
            if(root->right && root->left) {
                TreeNode* minNode = findMin(root->right);
                TreeNode* temp = root;
                minNode->left = root->left;
                root = root->right;
                delete temp;
                return root;
            }
        }
        if (val > root->val) {
            root->right = del(root->right, val); 
            return root;
        }
        if (val < root->val){
            root->left = del(root->left, val);
            return root;
        }
    }
    
private: 
    vector<TreeNode*> vt;
};
int main(){
    Solution s;
    s.generateTrees(2);
    return 0;
}
