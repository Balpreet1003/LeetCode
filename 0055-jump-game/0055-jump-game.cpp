class Solution {
    unordered_map<int,int>dp;
    int solve(vector<int>&nums,int i){
        if(i==nums.size()-1 || nums[i]+i>=nums.size()-1)return true;
        if(nums[i]==0)return false;
        if(dp.find(i)!=dp.end())return dp[i];

        bool ans=false;
        for(int j=1;j<=nums[i];j++){
            ans|=solve(nums,i+j);
        }
        return dp[i] = ans;
    }
public:
    bool canJump(vector<int>& nums) {
        return solve(nums,0);
    }
};