class Solution {
    int size;
    vector<vector<int>> row_trace;
    vector<vector<int>> col_trace;
    vector<vector<int>> box_trace;

    bool solve(vector<vector<char>>& board, int idx) {
        if (idx > 80)
            return true;
        int i = idx / 9, j = idx % 9; 

        if (board[i][j] == '.') {
            for (int x = 1; x <= 9; x++) {  
                if (!row_trace[i][x] && !col_trace[j][x] && !box_trace[(i/3)*3 + (j/3)][x]) {
                    board[i][j] = (char)('0' + x);
                    row_trace[i][x] = col_trace[j][x] = box_trace[(i/3)*3 + (j/3)][x] = true;

                    if (solve(board, idx + 1))
                        return true;

                    // backtrack
                    board[i][j] = '.';
                    row_trace[i][x] = col_trace[j][x] = box_trace[(i/3)*3 + (j/3)][x] = false;
                }
            }
            return false;
        } else {
            return solve(board, idx + 1);
        }
    }

public:
    Solution() : size(9),
        row_trace(9, vector<int>(10, false)),
        col_trace(9, vector<int>(10, false)),
        box_trace(9, vector<int>(10, false)) {}

    void solveSudoku(vector<vector<char>>& board) {
        // Fill initial constraints
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int d = board[i][j] - '0';
                    row_trace[i][d] = true;
                    col_trace[j][d] = true;
                    box_trace[(i/3)*3 + (j/3)][d] = true;
                }
            }
        }
        solve(board, 0);
    }
};
