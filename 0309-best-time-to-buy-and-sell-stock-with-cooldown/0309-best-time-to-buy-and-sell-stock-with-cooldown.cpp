class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int n = prices.size();
        int dp[n+1][3];
        memset(dp, 0, sizeof dp);

        for(int i = n-1; i >= 0; i--){
            for(int buy = 0; buy < 3; buy++){
                if(buy == 0){
                    dp[i][buy] = max(prices[i] + dp[i+1][2], dp[i+1][0]);
                }
                else if(buy == 1) { 
                    dp[i][buy] = max(- prices[i] + dp[i+1][0], dp[i+1][1]);
                }
                else {
                    dp[i][buy] = dp[i+1][1];
                }
            }
        }
        return dp[0][1];
    }
};