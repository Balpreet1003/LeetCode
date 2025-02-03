class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans=0,n=nums.size(),len=1;
        if(n==1)return 1;
        for(int i=1;i<n;i++){
            if(nums[i-1]<nums[i]) len++;
            else len=1;
            ans=max(ans,len);
        }
        len=1;
        for(int i=1;i<n;i++){
            if(nums[i-1]>nums[i]) len++;
            else len=1;
            ans=max(ans,len);
        }
        return ans;
    }
};