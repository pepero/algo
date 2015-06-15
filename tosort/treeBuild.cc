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

/* 
 
BUGS: 
 
TREE: stack 
 
void recInsert(TreeNode* root, int i)   
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
 
skills on pointers: 
In C, an argument is passed to a function that changes it, through a pointer. 
 
now in C++ , avoid **, try use *& 
instead: do it by reference! 
 
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
 
// or build root, then from root do as follows.
void insert_wiki(Node* node, int value) {
    if (value < node->key) {
        if (node->leftChild == NULL)
            node->leftChild = new Node(value);
        else
            insert_wiki(node->leftChild, value);
    } else {
        if(node->rightChild == NULL)
            node->rightChild = new Node(value);
        else
            insert_wiki(node->rightChild, value);
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
*/

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
   preOrderTree(byInsert(vi1));
}

  




