class Solution {
    vector<vector<bool>> trace_i;
    vector<vector<bool>> trace_j;
    vector<vector<bool>> trace_block;

    bool solve(vector<vector<char>>& a, int i){
        if (i >= 81) return true;

        int row = i / 9;
        int col = i % 9;
        int block_index = (row / 3) * 3 + (col / 3);

        if (a[row][col] == '.') {
            for (int k = 1; k <= 9; k++) {
                if (!trace_i[row][k-1] && !trace_j[col][k-1] && !trace_block[block_index][k-1]) {
                    a[row][col] = char(k + '0');
                    trace_i[row][k-1] = true;
                    trace_j[col][k-1] = true;
                    trace_block[block_index][k-1] = true;

                    if (solve(a, i+1)) return true;

                    a[row][col] = '.';
                    trace_i[row][k-1] = false;
                    trace_j[col][k-1] = false;
                    trace_block[block_index][k-1] = false;
                }
            }
        } else {
            return solve(a, i+1);
        }

        return false;
    }

public:
    void solveSudoku(vector<vector<char>>& a) {
        trace_i.resize(9, vector<bool>(9, false));
        trace_j.resize(9, vector<bool>(9, false));
        trace_block.resize(9, vector<bool>(9, false));

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (a[i][j] != '.') {
                    int num = a[i][j] - '1';
                    trace_i[i][num] = true;
                    trace_j[j][num] = true;
                    int block_index = (i / 3) * 3 + (j / 3);
                    trace_block[block_index][num] = true;
                }
            }
        }
        solve(a, 0);
    }
};