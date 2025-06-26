class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            int ans=0,maxi=0;
            for(int j=i;j<nums.size();j++){
                maxi=max(maxi,nums[j]);
                if(j-i+1<=k){
                    ans=max(ans,dp[j+1]+(maxi*(j-i+1)));
                }
                else{
                    break;
                }
            }
            dp[i]=ans;
        }

        return dp[0];
    }
};