class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long int max_num = *max_element(nums.begin(),nums.end()),count = 0;
        long long int l = 0,r = 0,ans = 0;
        while(r<nums.size()){
            if(nums[r] == max_num)count++;
            
            while(count>=k){
                if(nums[l]==max_num)count--;
                l++;
                ans += nums.size()-r;
            }    
            r++;
        }
        return ans;
    }
};