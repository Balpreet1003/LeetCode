class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans=0, k=1, n=nums.size(), i=0, j=0;
        while(j<n){
            if(nums[j]==1){
                j++;
            }
            else{
                if(k>0){
                    j++; k--;
                }
                else{
                    if(nums[i]==0)k++;
                    i++;
                }
            }
            ans=max(ans, j-i-1);
        }
        return ans;
    }
};