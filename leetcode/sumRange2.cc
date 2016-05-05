#include <vector>
#include <iostream>
using namespace std;

class SegmentTree2D {
public:
    class SegmentTree2DNode {
    public:
        int x0, y0, x1, y1, sum; 
        SegmentTree2DNode* ul;
        SegmentTree2DNode* ur;
        SegmentTree2DNode* bl;
        SegmentTree2DNode* br;
        SegmentTree2DNode(int x_0, int y_0, int x_1, int y_1, int s):
        x0(x_0), y0(y_0), x1(x_1), y1(y_1), sum(s), ul(0), ur(0), bl(0), br(0){}
    };
    SegmentTree2D(vector<vector<int>> &matrix){
        if (matrix.size() == 0) {
            root = 0;
            return;
        }
        root = build(matrix, 0, 0, matrix.size()-1, matrix[0].size()-1);
    }
    void update(int x, int y, int val) {
        update(root, x, y, val);
    }
    
    int getRangeSum(int x0, int y0, int x1, int y1) {
        return getRangeSum(root, x0, y0, x1, y1);
    }

    SegmentTree2DNode* build(vector<vector<int>> &matrix, int x_0, int y_0, int x_1, int y_1) {
        if (x_0 > x_1 || y_0 > y_1) return 0;
        if (x_0 == x_1 && y_0 == y_1) return new SegmentTree2DNode(x_0, y_0, x_1, y_1, matrix[x_0][y_0]);
        int x_m = x_0 + (x_1-x_0)/2;
        int y_m = y_0 + (y_1-y_0)/2;
        int s = 0;
        SegmentTree2DNode* ul, *ur, *bl, *br;
        ul = build(matrix, x_0, y_0, x_m, y_m);
        s += ul->sum;
        if (y_1 > y_m) {
            ur = build(matrix, x_0, y_m+1, x_m, y_1);
            s += ur->sum;
        }
        if (x_1 > x_m) {
            bl = build(matrix, x_m+1, y_0, x_1, y_m);
            s += bl->sum;
        }
        if (x_1 > x_m && y_1 > y_m) {
            br = build(matrix, x_m+1, y_m+1, x_1, y_1);
            s += br->sum;
        }
        SegmentTree2DNode* r = new SegmentTree2DNode(x_0, y_0, x_1, y_1, s);
        r->ul = ul;
        r->ur = ur;
        r->bl = bl;
        r->br = br;
        return r;
    } 
    int update(SegmentTree2DNode* node, int x, int y, int val) {
        if (node->x0 == x && node->x1 == node->x0 && node->y0 == node->y1 && node->y0 == y) {
            int d = val - node->sum;
            node->sum = val;
            return d;
        }
        int x_m = node->x0 + (node->x1-node->x0)/2;
        int y_m = node->y0 + (node->y1-node->y0)/2;
        int d = 0;
        if (node->x0 <= x && x <= x_m && node->y0 <= y && y <= y_m) {
            d = update(node->ul, x, y, val);
        }
        else if (node->x0 <= x && x <= x_m && y_m+1 <= y && y <= node->y1) {
            d = update(node->ur, x, y, val);
        }
        else if (x_m+1 <= x && x <= node->x1 && node->y0 <= y && y <= y_m) {
            d = update(node->bl, x, y, val);
        }
        else if (x_m+1 <= x && x <= node->x1 && y_m+1 <= y && y <= node->y1) {
            d = update(node->br, x, y, val);
        }
        node->sum +=d;
        return d;
    } 

    int getRangeSum(SegmentTree2DNode* node, int x0, int y0, int x1, int y1) {
        if (node->x0 == x0 && node->x1 == x1 && node->y0 == y0 && node->y1 == y1) {
            return node->sum;
        }
        int x_m = node->x0 + (node->x1-node->x0)/2;
        int y_m = node->y0 + (node->y1-node->y0)/2;
        int d = 0;
        if (x0 <= x_m && y0 <=y_m) {
            d += getRangeSum(node->ul, x0, y0, min(x1, x_m), min(y1, y_m));
        }
        if (x0 <= x_m && y1 > y_m) {
            d += getRangeSum(node->ur, x0, max(y0, y_m+1), min(x1, x_m), y1);
        }
        if (x1 > x_m && y0 <= y_m) {
            d += getRangeSum(node->bl, max(x_m+1, x0), y0, x1, min(y1, y_m));
        }
        if (x1 > x_m && y1 > y_m) {
            d += getRangeSum(node->br, max(x_m+1, x0), max(y_m+1, y0), x1, y1);
        }
        return d;
    } 
    SegmentTree2DNode* root;   
};


class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) {
        st = new SegmentTree2D(matrix);
    }

    void update(int row, int col, int val) {
        st->update(row, col, val);
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        st->getRangeSum(row1, col1, row2, col2);
    }
    SegmentTree2D* st;
};

int main() {
    vector<std::vector<int>> vv = {{1, 2}};
    NumMatrix nm (vv);
    cout << nm.sumRegion(0, 0, 0, 0) <<endl;
    cout << nm.sumRegion(0, 1, 0, 1) <<endl;
    cout << nm.sumRegion(0, 0, 0, 1) <<endl;
    nm.update(0, 0, 3);
    nm.update(0, 1, 5);
    cout << nm.sumRegion(0, 0, 0, 1) <<endl;

    vector<std::vector<int>> vv2 = 
    {{3, 0, 1, 4, 2},
     {5, 6, 3, 2, 1},
     {1, 2, 0, 1, 5},
     {4, 1, 0, 1, 7},
     {1, 0, 3, 0, 5}};
     NumMatrix nm2 (vv2);
     cout << nm2.sumRegion(2, 1, 4, 3)<<endl;
     nm2.update(3, 2, 2);
     cout << nm2.sumRegion(2, 1, 4, 3)<<endl;
}
// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.update(1, 1, 10);
// numMatrix.sumRegion(1, 2, 3, 4);