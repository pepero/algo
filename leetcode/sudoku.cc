#include <vector>
using namespace std;

int dir[5] = {0, 1, 0, -1, 0} ;
class Solution {
public:
    bool isDone(vector<vector<char>>& board, int& x, int& y) {
        for(int m= 0; m < 9; ++m) {
            for(int n= 0; n <9; ++n) {
                if (board[m][n]=='.') {
                    x = m;
                    y = n;
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<char>> row(9, vector<char>(9, '.'));
        vector<vector<char>> col(9, vector<char>(9, '.'));
        vector<vector<char>> s(9, vector<char>(9, '.'));
        for(int i= 0; i < 9; ++i) {
            for(int j= 0; j <9; ++j) {
                if (board[i][j]!='.') {
                    row[i][board[i][j]-1] = 1;
                    col[j][board[i][j]-1] = 1;
                    s[(i/3)*3+j/3][board[i][j]-1] = 1;
                }
            }
        }
        int x = -1, y = -1;
        if (isDone(board, x, y)) return;
        recursive(board, x, y, row, col, s);
    }
    void recursive (vector<vector<char>>& board, int i, int j, vector<vector<char>>& row, vector<vector<char>>& col, vector<vector<char>>& s){
        for(int k= 0; k < 9; ++k) {
            if (row[i][k] == '.' && col[j][k]=='.' && s[(i/3)*3+j/3][k]=='.') {
                board[i][j] = k+'0';
                row[i][k] = 1;
                col[j][k] = 1;
                s[(i/3)*3+j/3][k] = 1;
                
                for(int d = 0; d < 4; ++d) {
                    int nx = i+dir[d];
                    int ny = j+dir[d+1];
                    if (nx >=0 && nx<9 && ny>=0 && ny<9 && board[nx][ny] == '.') {
                        recursive(board, nx, ny, row, col, s);
                    }
                    int x = -1, y = -1;
                    if (isDone(board, x, y)) return;
                    else {
                        recursive (board, x, y, row, col, s);
                        if (isDone(board, x, y)) return;
                    }
                }
                board[i][j] = '.';
                row[i][k] = '.';
                col[j][k] = '.';
                s[(i/3)*3+j/3][k] = '.';
            }
        }
    }
};