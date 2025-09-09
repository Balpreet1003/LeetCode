class Solution {
    const int MOD = 1e9+7;
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int>dp(n+1,0);
        dp[n]=1;
        for(int day=n-1;day>0;day--){
            int ans=(n-day)<forget;
            for(int i=day+delay;i<min(n+1, day+forget);i++){
                ans=(ans+dp[i])%MOD;
            }
            dp[day]=ans;
        }
        return dp[1];
    }
};