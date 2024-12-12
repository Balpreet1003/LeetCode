class Solution {
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    int n, m;

    void dfs(vector<vector<char>>& board, vector<vector<int>>& visited, int i, int j) {
        if (visited[i][j] == 1) return;
        visited[i][j] = 1;
        for (int k = 0; k < 4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];
            if (x >= 0 && x < n && y >= 0 && y < m && board[x][y] == 'O') {
                dfs(board, visited, x, y);
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));
        vector<vector<char>> ans = board;

        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') dfs(board, visited, i, 0);
            if (board[i][m - 1] == 'O') dfs(board, visited, i, m - 1);
        }
        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O') dfs(board, visited, 0, j);
            if (board[n - 1][j] == 'O') dfs(board, visited, n - 1, j);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (ans[i][j] == 'O' && visited[i][j] == 0) ans[i][j] = 'X';
            }
        }
        board = ans;
    }
};