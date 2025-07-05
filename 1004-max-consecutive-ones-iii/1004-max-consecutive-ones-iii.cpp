class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size(),i=0,j=0,ans=0;
        while(j<n){
            if(nums[j]==1){
                ans=max(ans,j-i+1);
                j++;
            }
            else{
                if(k>0){
                    ans=max(ans,j-i+1);
                    j++;
                    k--;
                }
                else{
                    if(nums[i]==0){
                        k++;
                    }
                    i++;
                }
            }
        }
        return ans;
    }
};