class Solution {
    const int MOD = 1e9+7;
    int m, n;

    vector<vector<pair<long long,long long>>> dp;
    vector<vector<bool>> vis;

    pair<long long,long long> solve(vector<vector<int>>& grid, int i, int j){
        if(i == m-1 && j == n-1){
            return {grid[i][j], grid[i][j]};
        }

        if(vis[i][j]) return dp[i][j];
        vis[i][j] = true;

        long long maxi = LLONG_MIN;
        long long mini = LLONG_MAX;

        if(i+1 < m){
            auto down = solve(grid, i+1, j);
            long long a = down.first * grid[i][j];
            long long b = down.second * grid[i][j];
            maxi = max({maxi, a, b});
            mini = min({mini, a, b});
        }

        if(j+1 < n){
            auto right = solve(grid, i, j+1);
            long long a = right.first * grid[i][j];
            long long b = right.second * grid[i][j];
            maxi = max({maxi, a, b});
            mini = min({mini, a, b});
        }

        return dp[i][j] = {maxi, mini};
    }

public:
    int maxProductPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        dp.assign(m, vector<pair<long long,long long>>(n));
        vis.assign(m, vector<bool>(n, false));

        auto res = solve(grid, 0, 0);

        if(res.first < 0) return -1;
        return res.first % MOD;
    }
};