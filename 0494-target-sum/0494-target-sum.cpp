class Solution {
private:
    int n=1000;
    int getNumberOfWays(vector<int>&nums,int i ,int& target,int sum,vector<vector<int>>&dp){
        //bc
        if(sum==target && i==nums.size())
            return 1;
        if(i>=nums.size())
            return 0;

        if(dp[i][sum+n]!=-1)
            return dp[i][n+sum];
        //1 case
        //for +
        int plus=getNumberOfWays(nums,i+1,target,sum+nums[i],dp);
        //for -
        int minus=getNumberOfWays(nums,i+1,target,sum-nums[i],dp);
        return dp[i][n+sum] = plus+minus;
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<vector<int>>dp(nums.size()+1,vector<int>(2*n+1,-1));
        return getNumberOfWays(nums,0,target,0,dp);
    }
};