typedef vector<int> VecInt

class Solution {
public:
    int cntUniBST(VecInt v){
        v.clear();
        findDepth(0, root);;
        int min = *min_element(v.begin(), v.end());
        int max = *max_element(v.begin(), v.end());
        if (max>min+1) return false;
        else return true;
    }
    void findDepth(int depth, TreeNode* node){
        if(!node){
            v.push_back(depth);
        }
        else{
            findDepth(depth+1, node->left);
            findDepth(depth+1, node->right);
        }
    }
    vi v;
};
