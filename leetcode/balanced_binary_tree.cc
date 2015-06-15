/*
 * balanced_binary_tree.cc
 *
 *  Created on: Jun 15, 2015
 *      Author: shao
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
    	int min = 0, max = 0;
    	return isBal(root, min, max);
    }
//    int dfs(TreeNode* n, int cnt){
//        if(!n){
//            depth.insert(cnt);
//            if (depth.size() > 2)
//            if (depth.max() - depth.min ())
//        } else{
//            dfs(n->left, cnt+1);
//            dfs(n->right, cnt+1);
//        }
//    }
    bool isBal(TreeNode* node, int& min, int& max){
    	if (!node) {
    		min = 0; max = 0;
    		return true;
    	}
    	int min_l, min_r, max_l, max_r;
    	bool isBal_l = isBal(node->left, min_l, max_l);
    	if (!isBal_l) return false;
    	bool isBal_r = isBal(node->right,min_r, max_r);
    	if (!isBal_r) return false;
    	min = min(min_l, min_r) +1;
    	max = max(max_l, max_r) +1;
    	if (min +1 < max) return false;
    	return true;
    }
};


