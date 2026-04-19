class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>arr(n, -1);
        int mini=nums[n-1];
        for(int i=n-1;i>=0;i--)
        {
            arr[i]=min(mini, nums[i]);
            mini=arr[i];
        }
        int maxi=nums[0];
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi, nums[i]);
            if(maxi-arr[i]<=k)
                return i;
        }
        return -1;
    }
};