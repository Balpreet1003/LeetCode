class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        
        // If the starting point or the end point is blocked, return 0
        if (a[0][0] == 1 || a[n-1][m-1] == 1) return 0;
        
        // Initialize the starting point
        dp[0][0] = 1;
        
        // Fill the dp table
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (a[i][j] == 1) {
                    dp[i][j] = 0; // No paths through obstacles
                } else {
                    if (i > 0) dp[i][j] += dp[i-1][j]; // Add paths from above
                    if (j > 0) dp[i][j] += dp[i][j-1]; // Add paths from the left
                }
            }
        }
        
        // The result is the number of ways to reach the bottom-right corner
        return dp[n-1][m-1];
    }
};