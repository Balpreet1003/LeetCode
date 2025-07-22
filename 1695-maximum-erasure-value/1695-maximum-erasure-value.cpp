class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ans=0;
        int i=0,j=0,n=nums.size(),sum=0;
        unordered_map<int,int>m;
        while(j<n){
            if(m.count(nums[j])){
                m.erase(nums[i]);
                sum-=nums[i];
                i++;
            }
            else{
                m[nums[j]]++;
                sum+=nums[j];
                j++;
            }
            ans=max(ans,sum);
        }
        return ans;
    }
};