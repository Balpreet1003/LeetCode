class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>m;
        for(int i=n-1;i>=0;i--){
            if(m.find(nums[i])!=m.end())break;
            m[nums[i]]=1;
        }
        int x=m.size();
        int ans = (((n-x)/3) + ((((n-x)%3)==0) ? 0 : 1));
        return ans;
    }
};