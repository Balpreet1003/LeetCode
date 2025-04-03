class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        vector<int>right(n);
        int maxi=0;
        for(int i=n-1;i>=0;i--){
            right[i]=maxi;
            maxi=max(maxi,nums[i]);
        }
        maxi=nums[0];
        long long ans=0;
        for(int i=1;i<n-1;i++){
            ans=max(ans,(long long)(maxi-nums[i])*right[i]);
            maxi=max(maxi,nums[i]);
        }
        return ans;
    }
};