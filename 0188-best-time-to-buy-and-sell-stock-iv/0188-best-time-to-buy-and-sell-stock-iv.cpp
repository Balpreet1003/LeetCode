class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));

        for(int i = n-1; i >=0; i--){
            for(int buy = 0; buy < 2; buy++){
                for(int cnt = k; cnt > 0; cnt--){
                    if(buy == 1) {
                        dp[i][buy][cnt] = max(- prices[i] + dp[i+1][0][cnt], dp[i+1][1][cnt]);
                    }
                    else {
                        dp[i][buy][cnt] = max(prices[i] + dp[i+1][1][cnt-1], dp[i+1][0][cnt]);
                    }
                }
            }
        }
        return dp[0][1][k];
    }
};