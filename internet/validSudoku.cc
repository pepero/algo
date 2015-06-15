class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        m_board = board;
        deque<bool> dq (9, false);
        deque <deque<bool> > ddqq(9, dq);
        m_row = ddqq;
        m_col = ddqq;
        
        for (int i = 1; i <= 9; ++i){
            if (!valSudoku(i)) return false;
        }
        return true;
    }
    
    bool valSudoku (int n){
        for (int i = 0; i < n-2; ++i){
            if(m_board[n-1][i] != '.'){
                if (m_row[n-1][m_board[n-1][i]] || m_col[m_board[n-1][i]][i]){
                    return false;
                } 
                m_row[n-1][m_board[n-1][i]] = true;
                m_col[m_board[n-1][i]][i] = true;
            }
            if(m_board[i][n-1] != '.'){
                if (m_col[m_board[i][n-1]][n-1] || m_row[i][m_board[i][n-1]]){
                    return false;
                } 
                m_col[m_board[i][n-1]][n-1] = true;
                m_row[i][m_board[i][n-1]] = true;
            }
        }
        if (m_row[n-1][m_board[n-1][n-1]] || m_col[m_board[n-1][n-1]][n-1]){
            return false;
        } else {
            m_row[n-1][m_board[n-1][n-1]] = true;
            m_col[m_board[n-1][n-1]][n-1] = true;
        }
        return true;
    }
    
    vector<vector<char> > m_board;
    deque<deque<bool> > m_row;
    deque<deque<bool> > m_col;
};
