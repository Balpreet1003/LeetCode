class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int n=prices.size();
        int dp[n+1][2][3];
        memset(dp,0,sizeof dp);

        for(int i=n-1;i>=0;i--){
            for(int buy=0; buy<2; buy ++){
                for(int cnt = 2; cnt > 0; cnt--){
                    if(buy==1){
                        dp[i][buy][cnt]=max(-prices[i]+dp[i+1][0][cnt],dp[i+1][1][cnt]);
                    }
                    else{
                        dp[i][buy][cnt]=max(prices[i]+dp[i+1][1][cnt-1],dp[i+1][0][cnt]);
                    }
                }
            }
        }
        return dp[0][1][2];
    }
};