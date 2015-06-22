/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */



 #include <vector>

 using namespace std;


struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

typedef vector<vector<int> > VVI;
typedef vector<int> VI;
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vvi.clear();

        if(!root) return vvi;
        queue<TreeNode*> q;
        int curr = 1;
        int next = 0;
        int sofar = 0;
        q.push(root);
        VI vi;

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            sofar++;
            vi.push_back(node->val);

            if(node->left){
                q.push(node->left);
                next++;
            }
            if(node->right){
                q.push(node->right);
                next++;
            }
            if(sofar == curr){
                VI toAdd(vi);
                vvi.push_back(toAdd);
                vi.clear();
                curr = next;
                sofar = 0;
                next = 0;
            }
        }
        return vvi;
    }

    VVI vvi;
};
