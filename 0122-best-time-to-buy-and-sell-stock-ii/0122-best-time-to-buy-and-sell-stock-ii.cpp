class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        // 0 -> not buy 
        // 1 -> buy stock
        for (int i = n-1; i >= 0; i--) {
            for (int j = 0; j < 2; j++) {
                int ans = 0;
                if (j == 0) {
                    ans = max(prices[i] + dp[i + 1][1], dp[i + 1][0]);
                } else {
                    ans = max(-prices[i] + dp[i + 1][0], dp[i + 1][1]);
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][1];
    }
};