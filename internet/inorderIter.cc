typedef vector<int> VecInt

Struct Node {
	int val;
	Node* left;
	Node* right;
	bool visited;
	Node(int i): val(i), left(NULL), right(NULL), visited(false){};
}


void insertTree(TreeNode*& root, int i)
{
    if(!root) {
        root = new TreeNode(i);
    } else {
        if (i < root->value) {
            insertTree(root->left, i);
        } else {
            insertTree(root->right, i);
        }
    }
}

TreeNode* byInsert(VecInt v)
{
    TreeNode* root = NULL;
    for (int i = 0; i < v.size(); i++)
    {
        insertTree(root, v[i]);
    }
    return root;
}


void inorderIter(Node* root){
	if (!root) return;
	stack<Node*> stk;
	stk.push(root);
	Node* node = root;
	while(!stk.empty()) {
		if (node->left && node->left->visited) {
			stk.push(node->left);
		} else {
				node->visited = true;
				cout << node->val << end;
				stk.pop();
				if (node->right) stk.push(node->right);
		}
	}
}

int main(){
  int ints1[] = {1,2,3,4,5,6,7};
	VecInt vi (ints1, sizeof (ints1) / sizeof(ints1[0]);
	Node* root = byInsert(vi);
	inorderIter(root);
}



		


