class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = *max_element(nums.begin(),nums.end());
        int ans=1, len=0, n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==maxi){
                len++;
            }
            else{
                len=0;
            }
            ans=max(ans,len);
        }
        return ans;
    }
};