class Solution {
    vector<vector<int>>dp;
    int solve(vector<vector<int>>& nums, int i, int j){
        if(i>=nums.size())
            return 0;
        if(dp[i][j+1]!=-1)
            return dp[i][j+1];
        int ans=0;
        if(j==-1 || nums[i][0]>nums[j][1])
            ans=max(ans, solve(nums, i+1, i)+1);
        ans=max(ans, solve(nums, i+1, j));
        return dp[i][j+1]=ans;
        //return ans;
    }
    // int solve(vector<vector<int>>& nums){
    //     int n=nums.size();

    // }
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        dp.resize(pairs.size()+1, vector<int>(pairs.size()+1, -1));
        return solve(pairs, 0, -1);
    }
};