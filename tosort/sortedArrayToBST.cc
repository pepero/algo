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
    TreeNode* sortedArrayToBST(vector<int> &num){
        return sortedArrayToBST(0, num.size()-1);
    }

    TreeNode* sortedArrayToBST(int begin, int end){
        TreeNode *node =NULL;
        if(begin <= end) {
            int mid = (begin+end) / 2 ;
            node = new TreeNode(vi[mid]);
            node->left = sortedArrayToBST(begin, mid-1);
            node->right = sortedArrayToBST(mid+1, end);
        }
        return node;
    }
    VecInt vi;
};



int main()
{
   int ints1[]= {1, 2, 4};
   int ints2[]= {4, 3, 2, 1, 5, 6, 7};
   VecInt vi1(ints1, ints1 + sizeof ints1 / sizeof (int)); 
   VecInt vi2(ints2, ints2 + sizeof ints2 / sizeof (int)); 
   Solution s;
   s.vi = vi1;
 
   preOrderTree(s.buildTree2());
}

  




