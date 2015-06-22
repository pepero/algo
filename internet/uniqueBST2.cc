#include <vector>
#include <stddef.h>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
typedef vector <TreeNode*> VT;
typedef vector <vector<TreeNode*> > VVT;

class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        vvt.clear();
        VT vt0, vt1, vte;
        vt0.push_back(NULL);
        TreeNode* node1 = new TreeNode(1);
        vt1.push_back(node1);
        vvt.push_back(vt0);
        vvt.push_back(vt1);

        for (int i = 2; i <=n; ++i){
            vvt.push_back(vte);
            gen(i);
        }
           
        return vvt[n];
    }
   
    void gen(int n) {
        for(int i = 0; i < n; ++i){
            VT vt1 = vvt[i];
            VT vt2 = vvt[n-1-i];
            for(int j = 0; j < vt1.size(); ++j){
                TreeNode* node = new TreeNode (n);
                TreeNode* r;
                if (j > 0) {
                    r = recCopyTree(vt1[j]);
                    TreeNode* t = findMax(r);
                    t->right = node;
                } else{
                    r = node;
                }
                for(int k = 0; k < vt2.size(); ++k){
                    if (k > 0) {
                        TreeNode* s = recCopyTree(vt2[k], 1+i);
                        node->left = s;
                    } 
                    vvt[n].push_back(r);
                }
            }
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

    TreeNode* recCopyTree(TreeNode *src, int offset){
        TreeNode* root = NULL;
        if (src!=NULL){
            root = new TreeNode(src->val + offset);
            root->left = recCopyTree(src->left, offset);
            root->right = recCopyTree(src->right, offset);
        }
        return root;
    }

    TreeNode* findMax(TreeNode *root){
        if (!root) return NULL;
        while (root->right){
            root = root->right;
        }
        return root;
    }
private:
    VVT vvt;
};

int main(){
    Solution s;
    s.generateTrees(2);
    return 0;
}
