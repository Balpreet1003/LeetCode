class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        const int n = prices.size();
        int dp[n+1][2];
        memset(dp, 0, sizeof dp);

        for(int i = n-1; i >=0; i--){
            for(int buy = 0; buy < 2; buy++){
                if(buy == 1) {
                    dp[i][buy] = max(-prices[i] + dp[i+1][0], dp[i+1][1]);
                }
                else {
                    dp[i][buy] = max(prices[i] - fee +dp[i+1][1], dp[i+1][0]);
                }
            }
        }
        return dp[0][1];
    }
};