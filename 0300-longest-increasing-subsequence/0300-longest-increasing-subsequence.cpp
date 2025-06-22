class Solution {
    vector<vector<int>>dp;
    int solve(vector<int>& nums, int i, int prev) {
        if (i >= nums.size()) {
            return 1;
        }
        if(prev==-1){
            return max(solve(nums, i+1, i), solve(nums, i+1, prev));
        }
        if (dp[i][prev]!=-1) {
            return dp[i][prev];
        }
        int ans = 0;
        if (nums[i] > nums[prev]) {
            ans = max(ans, solve(nums, i + 1, i) + 1);
        }
        return dp[i][prev] = max(ans, solve(nums, i + 1, prev));
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n+1,vector<int>(n+1,-1));
        return solve(nums, 0, -1);
    }
};