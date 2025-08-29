class Solution {
    int n, m;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};

    bool is_valid_index(int i, int j) {
        return (i >= 0 && i < n && j >= 0 && j < m);
    }

    void dfs(vector<vector<char>>& board, vector<vector<bool>>& vis, int i, int j) {
        if(vis[i][j]) return;

        vis[i][j] = true;  // ✅ Mark visited

        for(int k = 0; k < 4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];
            if(is_valid_index(x, y) && board[x][y] == 'O' && !vis[x][y]) {
                dfs(board, vis, x, y);
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        n = board.size(), m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        // DFS from borders
        for(int i = 0; i < n; i++) {
            if(board[i][0] == 'O') dfs(board, vis, i, 0);
            if(board[i][m-1] == 'O') dfs(board, vis, i, m-1);
        }
        for(int j = 0; j < m; j++) {
            if(board[0][j] == 'O') dfs(board, vis, 0, j);
            if(board[n-1][j] == 'O') dfs(board, vis, n-1, j);
        }

        // Flip unvisited O → X
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == 'O' && !vis[i][j])
                    board[i][j] = 'X';
            }
        }
    }
};