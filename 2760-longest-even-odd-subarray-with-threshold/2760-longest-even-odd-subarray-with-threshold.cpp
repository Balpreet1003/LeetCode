class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        if(nums.size()==1)
            return nums[0]<=threshold && nums[0]%2==0;
        int ans=0, l=0, r=1;
        while(l<nums.size() && (nums[l]&1 || nums[l]>threshold)){
            l++;
        }

        if(l>=nums.size())
            return 0;
        r=l+1;
        while(r<nums.size()){
            if(nums[l]%2==0 && nums[l]<=threshold && nums[r]<=threshold && abs(nums[r]-nums[r-1])&1){
                r++;
            }
            else{
                l=r;
                r+=1;
            }
            ans=max(ans, r-l);
        }
        ans=max(ans, r-l);
        return ans;
    }
};