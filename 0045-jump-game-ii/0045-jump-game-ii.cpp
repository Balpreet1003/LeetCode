class Solution {
    unordered_map<long long ,int>dp;
    int solve(vector<int>&nums,int i){
        if(i==nums.size()-1)return 0;
        if(i>=nums.size() || nums[i]==0)return INT_MAX;
        if(dp.find(i)!=dp.end())return dp[i];

        int ans=INT_MAX;
        for(int j=1;j<=nums[i];j++){
            ans=min(ans,solve(nums,i+j));
        }
        return dp[i]=(ans==INT_MAX) ? ans : ans+1;
    }
public:
    int jump(vector<int>& nums) {        
        return solve(nums,0);
    }
};