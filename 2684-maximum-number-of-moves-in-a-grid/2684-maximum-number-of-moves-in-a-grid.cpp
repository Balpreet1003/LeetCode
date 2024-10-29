class Solution {
public:
    int maxMoves(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));        
        for (int j = m - 2; j >= 0; j--) {
            for (int i = 0; i < n; i++) {                
                int ans = 0;
                if (i + 1 < n && a[i][j] < a[i + 1][j + 1]) {
                    ans = max(ans, dp[i + 1][j + 1] + 1);
                }                
                if (a[i][j] < a[i][j + 1]) {
                    ans = max(ans, dp[i][j + 1] + 1);
                }                
                if (i - 1 >= 0 && a[i][j] < a[i - 1][j + 1]) {
                    ans = max(ans, dp[i - 1][j + 1] + 1);
                }
                dp[i][j] = ans;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, dp[i][0]);
        }
        
        return ans;
    }
};