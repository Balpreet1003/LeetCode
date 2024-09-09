class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int t) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;){
            for(int j=i+1;j<n;){
                int k=j+1,l=n-1;
                while(k<l){
                    int x=nums[i]+nums[j]+nums[k]+nums[l];
                    if(x==t){
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        k++;l--;
                        while(nums[k]==nums[k-1] && k<l)k++;
                        while(nums[l]==nums[l+1] && k<l)l--;
                    }
                    else if(x>t)l--;
                    else{
                        k++;
                    }
                }
                j++;
                while(j<n && nums[j]==nums[j-1])j++;
            }
            i++;
            while(i<n && nums[i]==nums[i-1])i++;
        }
        return ans;
    }
};