class Solution {
public:
    int minPathSum(vector<vector<int>>& a) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int n=a.size(),m=a[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        dp[n-1][m-1]=a[n-1][m-1];
        for(int i=n-2;i>=0;i--){
            dp[i][m-1]=a[i][m-1]+dp[i+1][m-1];
        }
        for(int j=m-2;j>=0;j--){
            dp[n-1][j]=a[n-1][j]+dp[n-1][j+1];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=m-2;j>=0;j--){
                dp[i][j]=a[i][j]+min(dp[i+1][j],dp[i][j+1]);
            }
        }
        return dp[0][0];
    }
};