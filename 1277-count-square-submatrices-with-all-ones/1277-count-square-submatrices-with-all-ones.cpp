class Solution {
    vector<vector<int>>dp;
    int n,m;
    int solve(vector<vector<int>>&a,int i,int j){
        if(i>=n || j>=m || a[i][j]==0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j]=min(solve(a,i+1,j),min(solve(a,i,j+1),solve(a,i+1,j+1)))+1;
    }
public:
    int countSquares(vector<vector<int>>& a) {
        int ans=0;
        n=a.size(),m=a[0].size();
        dp.assign(n+1,vector<int>(m+1,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans+=solve(a,i,j);
            }
        }
        return ans;
    }
};