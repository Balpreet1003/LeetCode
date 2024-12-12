class Solution {
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    int n, m;

    void dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int i, int j) {
        if (visited[i][j] == 1) return;
        visited[i][j] = 1;
        for (int k = 0; k < 4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];
            if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1 && visited[x][y] == 0) {
                dfs(grid, visited, x, y);
            }
        }
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 1) dfs(grid, visited, i, 0);
            if (grid[i][m - 1] == 1) dfs(grid, visited, i, m - 1);
        }

        for (int j = 0; j < m; j++) {
            if (grid[0][j] == 1) dfs(grid, visited, 0, j);
            if (grid[n - 1][j] == 1) dfs(grid, visited, n - 1, j);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && visited[i][j] == 0) ans++;
            }
        }
        return ans;
    }
};