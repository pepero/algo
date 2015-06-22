#include <iostream>
#include <vector>

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
/* 
 
    VecInt inorderTra(TreeNode* root){
        TreeNode* node = root;        
        while(node) {                 
            if(node->left) {          
                node = node->left;    
            }                         
            vi.push_back(node->val);  
            if(node->right) {         
                node = node->right;   
            }        
        }                             
        return vi;                    
    }                                 
*/

    VecInt inorderTra(TreeNode* root){
        stack<TreeNode*> stk;
        map<TreeNode*, bool> visited;
        if(!root) {
            return vi;
        } 
        stk.push(root); 
               
        while(!stk.empty()) {             
            node = stk.top();                            
            if(node->left && visited.find(node->left)==visited.end()) {          
                stk.push(node->left);    

            }                         
            vi.push_back(node->val);  
            if(node->right) {         
                node = node->right;   
            }        
        }                             
        return vi;                    
    }      
    vector<int> vi;
};

void recInsert(TreeNode*& root, int i)   
{                                       
    if(!root) {                         
      root = new TreeNode(i);           
    }                                   
    else {                              
        if (i < root->val) {            
            recInsert(root->left, i);   
        }                               
        else {                          
            recInsert(root->right, i);  
        }                               
    }                                   
}    
                                         
// build tree by insert                 
                                        
TreeNode* byInsert(VecInt v)            
{                                       
    TreeNode* root = NULL;              
    for (int i = 0; i < v.size(); i++) {
        recInsert(root, v[i]);          
    }                                   
    return root;                        
}    
void preOrderTree(TreeNode* node)
{
	if(!node) { return;};
		cout << node->val << endl;
		preOrderTree(node->left);
		preOrderTree(node->right);
}

int main()
{
   int ints1[]= {4, 2, 1};
   int ints2[]= {4, 3, 2, 1, 5, 6, 7};
   VecInt vi1(ints1, ints1 + sizeof ints1 / sizeof (int)); 
   VecInt vi2(ints2, ints2 + sizeof ints2 / sizeof (int)); 
   TreeNode *root = byInsert(vi1);
   Solution s;
   s.inorderTra(root);
   for(VecInt::const_iterator it=s.vi.begin();
        it!=s.vi.end(); ++it) {
       cout << *it << endl;
   }
}
