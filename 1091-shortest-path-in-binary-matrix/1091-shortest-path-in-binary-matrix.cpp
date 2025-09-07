class Solution {
    int dx[8] = {0,1,1,1,0,-1,-1,-1};
    int dy[8] = {1,1,0,-1,-1,-1,0,1};
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1) return -1;
        if (n == 1) return 1;

        queue<vector<int>> q;
        q.push({0, 0, 1});
        grid[0][0] = 1;

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            int x = curr[0];
            int y = curr[1];
            int h = curr[2];

            if (x == n-1 && y == n-1) return h;

            for (int l = 0; l < 8; l++) {
                int i = x + dx[l];
                int j = y + dy[l];
                if (i >= 0 && i < n && j >= 0 && j < n && grid[i][j] == 0) {
                    q.push({i, j, h + 1});
                    grid[i][j] = 1;
                }
            }
        }
        return -1;
    }
};