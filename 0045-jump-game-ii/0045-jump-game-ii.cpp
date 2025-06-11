class Solution {
    vector<int>dp;
    int solve(vector<int>&nums,int i){
        if(i==nums.size()-1)return 0;
        if(i>=nums.size() || nums[i]==0)return INT_MAX;
        if(dp[i]!=-1)return dp[i];

        int ans=INT_MAX;
        for(int j=1;j<=nums[i];j++){
            ans=min(ans,solve(nums,i+j));
        }
        return dp[i]=(ans==INT_MAX) ? ans : ans+1;
    }
public:
    int jump(vector<int>& nums) {
        dp=vector<int>(nums.size()+*max_element(nums.begin(),nums.end())+1,-1);
        return solve(nums,0);
    }
};