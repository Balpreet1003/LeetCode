class Solution {
    int n1,m1;
    vector<vector<long long>>dp;
    long long solve(vector<vector<int>>& waitCost,int i,int j){
        if(i==n1-1 && j==m1-1){
            return n1*m1;
        }
        if(i>=n1 || j>=m1){
            return LLONG_MAX;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        long long ans=min(solve(waitCost,i+1,j),solve(waitCost,i,j+1));
        return dp[i][j] = (ans==LLONG_MAX) ? ans : ans +(1LL*(i+1)*(j+1))+(1LL*waitCost[i][j]);
    }
public:
    long long minCost(int n, int m, vector<vector<int>>& waitCost) {
        n1=n,m1=m;
        dp.resize(n1+1,vector<long long>(m1+1,-1));
        return solve(waitCost,0,0)-waitCost[0][0];
    }
};