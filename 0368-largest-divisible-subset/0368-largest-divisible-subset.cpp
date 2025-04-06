class Solution {
    vector<int>ans;
    unordered_map<string,vector<int>>m;
    vector<int>solve(vector<int>&nums,int i,int prev){
        if(i==nums.size())return {};

        string key=to_string(i)+","+to_string(prev);
        if(m.find(key)!=m.end())return m[key];

        vector<int>ans=solve(nums,i+1,prev);

        if(prev==1 || nums[i]%prev==0){
            vector<int>a={nums[i]};
            vector<int>b=solve(nums,i+1,nums[i]);
            a.insert(a.end(),b.begin(),b.end());

            if(a.size()>ans.size())ans=a;
        }
        m[key]=ans;
        return ans;
    }

public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return solve(nums,0,1);
    }
};