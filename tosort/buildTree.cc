#include <vector>
#include <queue>
#include <cstddef>
#include <iostream>
#include <algorithm>

using namespace std;

typedef vector<int> vi;

struct TreeNode
{
    int value;
    TreeNode *left;
    TreeNode *right;
};

TreeNode* func(vi v, int index)
{
    TreeNode *tmp = NULL;
    if(index < v.size())
    {
        tmp = new TreeNode();
        tmp->value = v[index];
        tmp->left = func(v, 2*index + 1);
        tmp->right = func(v, 2*index + 2);
    }
    return tmp;
}

TreeNode* buildTreeLevel(vi v)
{
    func(v, 0);
}


void preOderTree(TreeNode* node)
{
	if(!node) { return;};
		cout << node->value << endl;
		preOderTree(node->left);
		preOderTree(node->right);
}
/*
 
BUGS: 
 
do not know the reason! 
have to figure it out! 
                                         
TreeNode* buildTreeByBFS(vi v)           
{                                        
    if(v.empty()) return NULL;           
    queue<TreeNode*> q;                  
    int N = v.size();                    
    TreeNode* root = new TreeNode();     
    q.push(root);                        
                                         
    for (int i = 0; i < N; i++)          
    {                                    
        TreeNode* node = q.front();      
        q.pop();                         
        if (v[i]==-1)                    
        {                                
            delete node;                 
            node = NULL;                 
        }                                
        else                             
        {                                
            node->value = v[i];          
            node->left = new TreeNode(); 
            node->right = new TreeNode();
            q.push(node->left);          
            q.push(node->right);         
        }                                
    }                                    
                                         
    while(!q.empty())                    
    {                                    
        TreeNode* node = q.front();      
        q.pop();                         
        delete node;                     
        node = NULL;                     
    }                                    
    return root;                         
}                                        
*/

TreeNode* buildTreeByBFS2(vi v)
{
    if(v.empty() || v[0] == -1) return NULL;
    queue<TreeNode*> q;
    int N = v.size();
    TreeNode* root = new TreeNode();
    root->value = v[0];
    q.push(root);

    for (int i = 1; i < N;i+=2)
    {
        TreeNode* node = q.front();
        q.pop();
        if(!node)
        {
            return NULL;
        }
        if(i < N-1){
          if(v[i] == -1)
          {
              node->left = NULL;
              q.push(node->left);
          }
          else{
              node->left = new TreeNode();
              node->left->value = v[i];
              q.push(node->left);
          }
          if(v[i+1] == -1)
          {
              node->right = NULL;
              q.push(node->right);
          }
          else{

              node->right = new TreeNode();
              node->right->value = v[i+1];
              q.push(node->right);
          }
        }
        else{
          if(v[i] == -1)
          {
              node->left = NULL;
              q.push(node->left);
          }
          else{
              node->left = new TreeNode();
              node->left->value = v[i];
              q.push(node->left);
          }
        }				
    }
    return root;
}

class buildPreOrder {
public:
    vector <TreeNode*> buildTreePreOrder(VI vi){
        if(vi.empty()) return NULL;
        stack<TreeNode*> stk;
        TreeNode* sofar;
        recBuild(vi, stk, sofar);
        return forest;
    }

    void recBuild(VI v, stack<TreeNode*>& stk, TreeNode* sofar){
        if(v.empty()))
        {
            return forest.push_back(sofar);
        }
        else{
            int i = v.begin();
            VI v_rest (v.begin()+1, v.end());
            while(!stk.empty())
            {
                // take left
                TreeNode* nodePop = stk.top();
                nodePop->left = new TreeNode(i);
                stack<TreeNode*> stkNextLeft;
                for(stack<TreeNode*>::const_iterator it = stk.begin(), 
                    it!=stk.end(); ++it)
                {
                    stkNextLeft.push(new TreeNode(it->value));
                }
                stkNextLeft.pop();
                stkNextLeft.push(nodePop->left);
                TreeNode* treeNext = copyTree(sofar);
                recBuild(v_rest, stkNextLeft, treeNext);

                // take right
                TreeNode* nodePop = stk.top();
                nodePop->right = new TreeNode(i);
                stack<TreeNode*> stkNextRight;
                for(stack<TreeNode*>::const_iterator it = stk.begin(), 
                    it!=stk.end(); ++it)
                {
                    stkNextRight.push(new TreeNode(it->value));
                }
                stkNextRight.pop();
                stkNextRight.push(nodePop->right);
                TreeNode* treeNext = copyTree(sofar);
                recBuild(v_rest, stkNextRight, treeNext);

                // update
                stk.pop();
            }
        }
    }

    TreeNode* copyTree(TreeNode* tNode){
        if(!tNode) return NULL;
        TreeNode *root = new TreeNode(tNode->value);
        root->left = copyTree(tNode->left);
        root->right = copyTree(tNode->right);
        return root;
    }

    vector <TreeNode*> forest;
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
            v.push_back(depth);
        }
        else{
            findDepth(depth+1, node->left);
            findDepth(depth+1, node->right);
        }
    }
    vi v;
};

int main()
{
    int x[] = {1,2,2,3,3,-1,-1,4,4};
    int x1[] = {1,2,2,3,3,3,3,4,4,4,4,4,4,-1,-1,5,5};
    vi tree(x, x + sizeof x / sizeof x[0]);
    TreeNode* root = buildTreeByBFS2(tree);
    preOderTree(root);

    Solution s;
    if(s.isBalancedBT(root)) cout<< "balanced" << endl;
    else cout << "not balanced"<< endl;
    int size = s.v.size();

    for(int i=0; i<size; i++){
      cout << s.v[i] << endl;
    }
}




