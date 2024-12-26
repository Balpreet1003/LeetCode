class Solution {
    int x=0;
    int solve(vector<int>&a,int i,int& t,int sum,vector<vector<int>>&dp){
        if(sum==t && i==a.size())return 1;
        if(i>=a.size()) return 0;
        if(dp[i][sum+x]!=-1)return dp[i][sum+x];
        return dp[i][x+sum]=solve(a,i+1,t,sum+a[i],dp)+solve(a,i+1,t,sum-a[i],dp);
    }
public:
    int findTargetSumWays(vector<int>& a, int t) {
        int n=a.size();
        x=accumulate(a.begin(),a.end(),0);
        vector<vector<int>>dp(n+1,vector<int>(2*x+1,-1));
        return solve(a,0,t,0,dp);
    }
};