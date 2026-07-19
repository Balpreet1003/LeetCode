class Solution {
    public int longestConsecutive(int[] nums) {
        Arrays.sort(nums);
        int len=1, ans=nums.length==0?0:1;
        for(int i=1;i<nums.length;i++)
        {
            if(nums[i]-nums[i-1]==1)
                len++;
            else if(nums[i]==nums[i-1])
                continue;
            else
            {
                len=1;
            }
            ans=Math.max(ans, len);
        }
        return ans;
    }
}