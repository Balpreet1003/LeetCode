class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len=1, ans=nums.size()==0?0:1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]-nums[i-1]==1)
                len++;
            else if(nums[i]==nums[i-1])
                continue;
            else
            {
                len=1;
            }
            ans=max(ans, len);
        }
        return ans;
    }
};