// Write a program to solve a Sudoku puzzle by filling the empty cells.

// Empty cells are indicated by the character '.'.

// You may assume that there will be only one unique solution.

class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        vector<vector<bool> > rows(9, vector<bool>(9, false));
        vector<vector<bool> > cols(9, vector<bool>(9, false));
        vector<vector<bool> > blks(9, vector<bool>(9, false));
        
        for(int i = 0; i < 9; ++i)
            for(int j = 0; j < 9; ++j)
                if(board[i][j] >= '1' && board[i][j] <= '9') {
                    int num = board[i][j]-'1';
                    rows[i][num] = true;
                    cols[j][num] = true;
                    blks[3*(i/3)+j/3][num] = true;
                }
        
        helper(board, rows, cols, blks, 0, 0);
    }
    
    bool helper(vector<vector<char> > &board,
                vector<vector<bool> > &rows,
                vector<vector<bool> > &cols,
                vector<vector<bool> > &blks,
                int row, int col) {
        if(col == 9) {
            col = 0;
            ++row;
        }
        if(row == 9) return true;
        
        if(board[row][col] != '.')
            return helper(board,rows,cols,blks,row,col+1);
        for(int i = 0; i < 9; ++i) {
            if(!rows[row][i] && !cols[col][i] && !blks[3*(row/3)+col/3][i]) {
                board[row][col] = '1'+i;
                rows[row][i] = true;
                cols[col][i] = true;
                blks[3*(row/3)+col/3][i] = true;
                if(helper(board,rows,cols,blks,row,col+1)) return true;
                board[row][col] = '.';
                rows[row][i] = false;
                cols[col][i] = false;
                blks[3*(row/3)+col/3][i] = false;
            }
        }
        return false;
    }
    
    
};
