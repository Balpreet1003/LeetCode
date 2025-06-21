class Solution {
public:
    int count(vector<int> nums)
    {
        int ans=0;
        for(int i=0;i<nums.size();i++)
            ans += abs(nums[i]-i*2); 
        return ans;
    }
    int minSwaps(vector<int>& nums) 
    {
        vector<int> e,o;
        for(int i=0;i<nums.size();i++)
            {
                if(nums[i]%2)
                    o.push_back(i);
                else
                    e.push_back(i);
            }
        if(abs((int)o.size()-(int)e.size())>1)
            return -1;
        int ans = INT_MAX;
        if(o.size()>=e.size())
            ans = min(ans,count(o));
        if(e.size() >= o.size())
            ans = min(ans,count(e));
        return ans;
    }
};