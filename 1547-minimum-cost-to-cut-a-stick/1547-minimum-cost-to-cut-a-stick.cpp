class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int m = cuts.size();
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(m + 2, vector<int>(m + 2, 0));
        for (int i = m; i > 0; i--) {
            for (int j = 1; j <= m; j++) {
                int ans = INT_MAX;
                for (int k = i; k <= j; k++) {
                    ans = min(ans, cuts[j + 1] - cuts[i - 1] + dp[i][k - 1] +
                                       dp[k + 1][j]);
                }
                dp[i][j] = (ans == INT_MAX) ? 0 : ans;
            }
        }
        return dp[1][m];
    }
};