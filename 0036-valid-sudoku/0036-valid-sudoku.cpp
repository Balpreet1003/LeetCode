class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> rows(9, vector<int>(9, 0));
        vector<vector<int>> cols(9, vector<int>(9, 0));
        vector<vector<vector<int>>> box(3, vector<vector<int>>(3, vector<int>(9, 0)));

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;

                int num = board[i][j] - '1';

                if (rows[i][num] || cols[j][num] || box[i / 3][j / 3][num]) {
                    return false;
                }

                rows[i][num] = 1;
                cols[j][num] = 1;
                box[i / 3][j / 3][num] = 1;
            }
        }

        return true;
    }
};