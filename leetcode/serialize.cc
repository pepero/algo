class Codec {
public:
    string serialize(TreeNode* root) {
        ostringstream out;
        serialize(root, out);
        return out.str();
    }

    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserialize(in);
    }
private:
    void serialize(TreeNode* root, ostringstream& out) {
        if (root) {
            out << root->val << ' ';
            serialize(root->left, out);
            serialize(root->right, out);
        } else {
            out << "# ";
        }
    }
    TreeNode* deserialize(istringstream& in) {
        string val;
        in >> val;
        if (val == "#")
            return nullptr;
        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserialize(in);
        root->right = deserialize(in);
        return root;
    }
};

class TrieNode
{
public:
    TrieNode *next[26];
    bool is_word;

    // Initialize your data structure here.
    TrieNode(bool b = false)
    {
        memset(next, 0, sizeof(next));
        is_word = b;
    }
};

class Trie
{
    TrieNode *root;
public:
    Trie()
    {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string s)
    {
        TrieNode *p = root;
        for(int i = 0; i < s.size(); ++ i)
        {
            if(p -> next[s[i] - 'a'] == NULL)
                p -> next[s[i] - 'a'] = new TrieNode();
            p = p -> next[s[i] - 'a'];
        }
        p -> is_word = true;
    }

    // Returns if the word is in the trie.
    bool search(string key)
    {
        TrieNode *p = find(key);
        return p != NULL && p -> is_word;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix)
    {
        return find(prefix) != NULL;
    }

private:
    TrieNode* find(string key)
    {
        TrieNode *p = root;
        for(int i = 0; i < key.size() && p != NULL; ++ i)
            p = p -> next[key[i] - 'a'];
        return p;
    }
};

int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>v(n);
        v[0] = 1;
        for(int i = 1; i < n; ++i) {
            int maxL = 0;
            for(int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    maxL = max(maxL, v[j]);
                }
            }
            v[i] = maxL+1;
        }
        return *max_element(v.begin(), v.end());
    }

MinHeap(int cap) {
	capacity = cap;
	heapsize = 0;
	int* harray = new int[cap];	
}

int MinHeap::parent(int i) {
	return (i-1)/2;
}

int MinHeap::left(int i) {
	return i*2 + 1;
}

int MinHeap::right(int i) {
	return i*2 + 2;
}

void MinHeap::swap(int i, int j) {
	int t = harray[i];
	harray[i] = harray[j];
	harray[j] = t;
}

void MinHeap::insert(int k){
	if (heapsize == capcity) {
		return;
	}
	harray[heapsize-1] = k;
	i = heapsize-1;
	while(i > 0 && harray[i] < harray[parent(i)]) {
		swap(i, parent(i));
		i = parent(i);
	}
}

void MinHeap::increase(int i, int newval){
	harray[i] = newval;
	while(2*i + 2< capacity && harray[i] > harray[right(i)]) {
		swap(i, right(i));
		i = right(i);
	}
}

// top-down recursive:
void MinHeap::heapify(int i){
	int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i])
        smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(i, smallest);
        MinHeapify(smallest);
    }
}

// top-down iterative:
void MinHeap::heapify_iterative(int i) {
	int j = 0;
	while (2*i+2 < capacity) {
		j = 2*i+1;
		if (!less (left(i), right(i))) j++;
		if (less (harray[i], harray[j])) break;
		swap (i, j); 
		i = j;
	}
}

int MinHeap::extract(){
	if (heapsize == 0) return INT_MAX;
	if (heapsize == 1) {
		heapsize--;
		return harray[0];
	}
	int t = harray[0];
	heapsize--;
	heapify(0);
	return t;
}

typedef int pageid;
typedef int userid;
typedef pageid[3] sequence;
typedef int sequence_count;

const int num_pages = 1000; //where 1-1000 inclusive are valid pageids
const int num_passes = 4;
std::unordered_map<userid, sequence> userhistory;
std::unordered_map<sequence, sequence_count> visits;
sequence_count max_count=0;
sequence max_sequence={};
userid curuser;
pageid curpage;
for(int pass=0; pass<num_passes; ++pass) { 
    std::ifstream logfile("log.log");
    pageid minpage = num_pages/num_passes*pass; //where first page is in a range
    pageid maxpage = num_pages/num_passes*(pass+1)+1;
    if (pass==num_passes-1) //if it's last pass, fix rounding errors
        maxpage = MAX_INT;
    while(logfile >> curuser >> curpage) { //read in line
        sequence& curhistory = userhistory[curuser]; //find that user's history
        curhistory[2] = curhistory[1];
        curhistory[1] = curhistory[0];
        curhistory[0] = curhistory[curpage]; //push back new page for that user
        //if they visited three pages in a row
        if (curhistory[2] > minpage && curhistory[2]<maxpage) { 
            sequence_count& count = visits[curhistory]; //get times sequence was hit
            ++count; //and increase it
            if (count > max_count) { //if that's new max
                max_count = count;  //update the max
                max_sequence = curhistory; //arrays, so this is memcpy or something
            }
        }
    }
}
std::cout << "The sequence visited the most is :\n";
std::cout << max_sequence[2] << '\n';
std::cout << max_sequence[1] << '\n';
std::cout << max_sequence[0] << '\n';
std::cout << "with " << max_count << " visits.\n";


struct comparator {
 bool operator()(int i, int j) {
 return i > j;
 }
};
priority_queue<int, std::vector<int>, comparator> minHeap;

struct LessThanByAge
{
  bool operator()(const Person& lhs, const Person& rhs) const
  {
    return lhs.age < rhs.age;
  }
};
std::priority_queue<Person, std::vector<Person>, LessThanByAge> pq;


public TreeNode buildTree(int[] preorder, int[] inorder) {
    return helper(0, 0, inorder.length - 1, preorder, inorder);
}

public TreeNode helper(int preStart, int inStart, int inEnd, int[] preorder, int[] inorder) {
    if (preStart > preorder.length - 1 || inStart > inEnd) {
        return null;
    }
    TreeNode root = new TreeNode(preorder[preStart]);
    int inIndex = 0; // Index of current root in inorder
    for (int i = inStart; i <= inEnd; i++) {
        if (inorder[i] == root.val) {
            inIndex = i;
        }
    }
    root.left = helper(preStart + 1, inStart, inIndex - 1, preorder, inorder);
    root.right = helper(preStart + inIndex - inStart + 1, inIndex + 1, inEnd, preorder, inorder);
    return root;
}

class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {

        if(preorder.size()==0)
            return NULL;

        stack<int> s;
        stack<TreeNode *> st;
        TreeNode *t,*r,*root;
        int i,j,f;

        f=i=j=0;
        s.push(preorder[i]);

        root = new TreeNode(preorder[i]);
        st.push(root);
        t = root;
        i++;

        while(i<preorder.size())
        {
            if(!st.empty() && st.top()->val==inorder[j])
            {
                t = st.top();
                st.pop();
                s.pop();
                f = 1;
                j++;
            }
            else
            {
                if(f==0)
                {
                    s.push(preorder[i]);
                    t -> left = new TreeNode(preorder[i]);
                    t = t -> left;
                    st.push(t);
                    i++;
                }
                else 
                {
                    f = 0;
                    s.push(preorder[i]);
                    t -> right = new TreeNode(preorder[i]);
                    t = t -> right;
                    st.push(t);
                    i++;
                }
            }
        }

        return root;
    }
};

class Solution {
public:
    TreeNode *buildTree(vector<int> &pre, vector<int> &in) {
        int i=0,j=0;
        TreeNode *root=new TreeNode(0x80000000);
        TreeNode *pp=NULL,*ptr=root;
        stack<TreeNode*> sn;sn.push(root);
        while (j<in.size()) {
            if (sn.top()->val==in[j]) {
                pp=sn.top();
                sn.pop();
                j++;
            } else if (pp) {
                ptr=new TreeNode(pre[i]);
                pp->right=ptr;pp=NULL;
                sn.push(ptr);
                i++;
            } else {
                ptr=new TreeNode(pre[i]);
                sn.top()->left=ptr;
                sn.push(ptr);
                i++;
            }
        }
        ptr=root->left;delete root;
        return ptr;
    }
}; 

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if(inorder.size() == 0)return NULL;
        TreeNode *p;
        TreeNode *root;
        stack<TreeNode *> stn;

        root = new TreeNode(postorder.back()); 
        stn.push(root); 
        postorder.pop_back(); 

        while(true)
        {
            if(inorder.back() == stn.top()->val) 
            {
                p = stn.top();
                stn.pop(); 
                inorder.pop_back(); 
                if(inorder.size() == 0) break;
                if(stn.size() && inorder.back() == stn.top()->val)
                    continue;
                p->left = new TreeNode(postorder.back()); 
                postorder.pop_back();
                stn.push(p->left);
            }
            else 
            {
                p = new TreeNode(postorder.back());
                postorder.pop_back();
                stn.top()->right = p; 
                stn.push(p); 
            }
        }
        return root;
    }
