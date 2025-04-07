class Solution {
public:

    bool ifPartition(vector<int>&nums,int target, int index,vector<vector<int> >&dp){
        int n=nums.size();
        if(target==0 )
            return 1;
        if(target<0 || index>=n )
            return 0;

        if(dp[index][target] !=-1)
            return dp[index][target];

        //include
        bool include=0;
        if((target-nums[index])>=0)
            include = ifPartition(nums,target-nums[index],index+1,dp);
        bool exclude = ifPartition(nums,target,index+1,dp);
        dp[index][target] = (include || exclude);
        return dp[index][target];
    }

    bool ifPartition(vector<int>&nums,int target){
        int n=nums.size();
        vector<vector<int> >dp(n+1,vector<int>(target+1,0));

        for(int i=0;i<n;i++){
            dp[i][0]=1;
        }

        for(int index=n-1;index>=0;index--){
            for(int tar=1;tar<=target;tar++){
                bool include=0;
                if((tar-nums[index])>=0)
                    include = dp[index+1][tar-nums[index]];
                bool exclude = dp[index+1][tar];
                dp[index][tar] = (include || exclude);
                
            }
        } 
        return dp[0][target];
    }

    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i =0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum & 1)
            return false;
        int target=sum/2;
        int index=0;
        // vector<vector<int> >dp(nums.size()+2,vector<int>(target+1,-1));
        // return ifPartition(nums,target,index,dp);

        return ifPartition(nums,target);
    }
};