class Solution {
public:
    bool check(vector<int>& nums) {
        int cnt=0, n=nums.size();
        for(int i=1;i<n;i++)
        {
            if(nums[i]<nums[i-1])
                cnt++;
            if(cnt>1)
                return false;
        }
        return cnt==1 ? (nums[0]>=nums[n-1]) : true;
    }
};