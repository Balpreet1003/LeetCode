class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dp(n,1),trace(n,-1);;
        int maxi=-1;
        for(int i=0;i<n;i++){
            trace[i]=i;
            for(int j=i-1;j>=0;j--){
                if(nums[i]%nums[j]==0){
                    if(dp[i]<dp[j]+1){
                        dp[i]=dp[j]+1;
                        trace[i]=j;
                    }
                }
                if(maxi!=-1 && dp[maxi]<dp[i]){
                    maxi=i;
                }
                if(maxi==-1){
                    maxi=i;
                }
            }
        }
        vector<int>ans;
        while(maxi!=trace[maxi]){
            ans.push_back(nums[maxi]);
            maxi=trace[maxi];
        }
        ans.push_back(nums[maxi]);
        return ans;
    }
};