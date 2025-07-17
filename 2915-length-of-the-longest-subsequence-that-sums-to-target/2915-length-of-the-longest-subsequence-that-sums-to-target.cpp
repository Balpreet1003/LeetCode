class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, INT_MIN));
        for (int i = 0; i <= n; i++)
            dp[i][0] = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int tar = 0; tar <= target; tar++) {
                if (tar - nums[i] >= 0) {
                    dp[i][tar] = max(dp[i][tar], dp[i + 1][tar - nums[i]] + 1);
                }
                dp[i][tar] = max(dp[i][tar], dp[i + 1][tar]);
            }
        }
        int ans = dp[0][target];
        return ans < 0 ? -1 : ans;
    }
};