class Solution {
    int solve(vector<vector<int>>& grid, int i, int j) {
        if (i >= grid.size() || j >= grid[0].size() || i < 0 || j < 0 || grid[i][j] == 0) 
            return 0;
        int fish = grid[i][j];
        grid[i][j] = 0;
        return fish + solve(grid, i - 1, j) + solve(grid, i + 1, j) + solve(grid, i, j - 1) + solve(grid, i, j + 1);
    }

public:
    int findMaxFish(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] != 0) {
                    ans = max(ans, solve(grid, i, j));
                }
            }
        }
        return ans;
    }
};