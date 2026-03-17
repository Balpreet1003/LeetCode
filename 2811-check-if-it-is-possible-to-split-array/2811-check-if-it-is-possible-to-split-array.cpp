class Solution {
    vector<vector<int>>dp;
    bool solve(vector<int>& nums, int& m, int i, int j){
        if(i==j)
            return true;
        if((nums[j]-(i==0?0:nums[i-1]))<m)
            return false;
        if(dp[i][j]!=-1)
            return dp[i][j];
        bool ans=false;
        for(int x=i;x<j;x++){
            ans=ans || (solve(nums, m, i, x) && solve(nums, m, x+1, j));
        }
        return dp[i][j]=ans;
    }
public:
    bool canSplitArray(vector<int>& nums, int m) {
        int n=nums.size();
        if(n==2)
            return true;
        for(int i=1;i<n;i++){
            nums[i]+=nums[i-1];
        }
        dp.resize(n+1, vector<int>(n, -1));
        return solve(nums, m, 0, n-1);
    }
};