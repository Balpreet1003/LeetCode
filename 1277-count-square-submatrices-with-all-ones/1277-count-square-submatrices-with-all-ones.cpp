class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        int dp[n][m];
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    dp[i][j]=0;
                    continue;
                }
                if(i==0 || j==0){
                    dp[i][j]=1;
                }
                else{
                    dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
                }
                ans+=dp[i][j];
            }
        }
        return ans;
    }
};