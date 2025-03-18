class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int ans=0,currSum=0,xorSum=0,i=0,j=0,n=nums.size();
        while(j<n){
            currSum+=nums[j];
            xorSum^=nums[j];
            while(currSum!=xorSum){
                currSum-=nums[i];
                xorSum^=nums[i];
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;

    }
};