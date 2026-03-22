class Solution {
    vector<vector<unsigned long long>>dp;
public:
    int change(int amount, vector<int>& nums) {
        int n=nums.size();
        dp.assign(n+1, vector<unsigned long long>(amount+1, 0));
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }
        for(int i=n-1;i>=0;i--){
            for(int x=1;x<=amount;x++){
                if(nums[i]<=x)
                    dp[i][x]+=dp[i][x-nums[i]];
                dp[i][x]+=dp[i+1][x];
            }
        }
        return dp[0][amount];
    }
};