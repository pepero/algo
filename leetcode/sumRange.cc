#include <vector>
#include <cstddef>
using namespace std;

class SegmentTree {
    class SegmentTreeNode {
    public:
        int start;
        int end;
        int sum;
        SegmentTreeNode* left;
        SegmentTreeNode* right;
        SegmentTreeNode(int v, int l, int r):start(l), end(r), sum(v), left(NULL), right(NULL){}
    };
    public:
            SegmentTreeNode* root;
    SegmentTree(vector<int>& v) {
        root = build(v, 0, v.size()-1);
    }
    void update(int v, int p) {
        update(root, v, p);
    }
    int sumRange(int i, int j){
        return sumRange(root, i, j);
    }
    private:
    SegmentTreeNode* build(vector<int>& v, int l, int r) {
        if (l>r) return NULL;
        if (l== r) {
            return new SegmentTreeNode(v[l], l, r);
        }
        int m = l + (r-l)/2;
        SegmentTreeNode* ls = build(v, l, m);
        SegmentTreeNode* rs= build(v, m+1, r);
        int lsum = ls?ls->sum:0;
        int rsum = rs?rs->sum:0;
        SegmentTreeNode* s = new SegmentTreeNode(lsum+rsum, l, r);
        s->left = ls;
        s->right = rs;
        return s;
    }
    int update(SegmentTreeNode* t, int v, int p) {
        if (!t) return 0;
        if (t->start == t->end == p) {
            t->sum = v;
            return v;
        }
        int m = t->start + (t->end -t->start)/2;
        if(p<=m) {
            t->sum = update(t->left, v, p) + (t->right?t->right->sum:0);
        } else {
            t->sum = update(t->right, v, p) + (t->left?t->left->sum:0);
        }
        return t->sum;
    }
    int sumRange(SegmentTreeNode* t, int i, int j) {
        if (t->start>=i &&t->end <=j) return t->sum;
        int m = t->start + (t->end -t->start)/2;
        if(j<=m) {
            return sumRange(t->left, i, j);
        } 
        if(m<i){
            return sumRange(t->right, i, j);
        } else {
            return sumRange(t->left, i, m) + sumRange(t->right, m+1, j);
        }
    }
};


class NumArray {
public:
    NumArray(vector<int> &nums) {
        st = new SegmentTree(nums);
    }

    void update(int i, int val) {
        st->update(val, i);
    }

    int sumRange(int i, int j) {
        return st->sumRange(i, j);
    }
    class SegmentTree *st;
};

int main(){
    std::vector<int> v = {-1};
    NumArray na(v);
    na.sumRange(0,0);
    na.update(0,1);
    na.sumRange(0,0);
}

// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);