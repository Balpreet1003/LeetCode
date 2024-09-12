class Solution {
public:
    int minimumTotal(vector<vector<int>>& a) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int n=a.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        for(int j=0;j<n;j++){
            dp[n-1][j]=a[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            vector<int>temp(n+1,0);
            for(int j=0;j<=i;j++){
                dp[i][j]=min(dp[i+1][j],dp[i+1][j+1])+a[i][j];
            }
        }
        return dp[0][0];
    }
};