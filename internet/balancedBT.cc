#include <vector>
#include <algorithm>

typedef vector<int> vi;

class TreeNode{
    int value;
    TreeNode *left;
    TreeNode *right;
}
class Solution {
public:
    bool isBalancedBT(TreeNode* root){
        v.clear();
        findDepth(0, root);;
        int min = *min_element(v.begin(), v.end());
        int max = *max_element(v.begin(), v.end());
        if (max>min+1) return false;
        else return true;
    }
    void findDepth(int depth, TreeNode* node){
        if(!node){
            vi.push_back(depth);
        }
        else{
            findDepth(i+1, node->left);
            findDepth(i+1, node->right);
        }
    }


    int getHeight(TreeNode* node){
        if(!node) { return; }
        int l = getHeight(node->left);
        int r = getHeight(node->right);
        if(l==-1 || r ==-1 || abs(l-r)>1) {
            return -1;
        }
        return max(l, r)+1;
    }


    vi v;
};

int main(){
    Solution

    // Showing the first failed test case.
    // {1,2,2,3,3,3,3,4,4,4,4,4,4,#,#,5,5}


}
