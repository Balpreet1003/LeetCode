class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans=0,i=0,j=0;
        while(j<nums.size()){
            if((nums[j]-nums[i])<=(2*k)){
                ans=max(ans,j-i+1);
                j++;
            }
            else{
                // ans=max(ans,j-i+1);
                i++;
            }
        }
        return ans;
    }
};