class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());

        for(int i=0;i<n;i+=3){
            int x=nums[i],y=nums[i+1],z=nums[i+2];
            if(z-x<=k){
                ans.push_back({x,y,z});
            }
            else{
                return {};
            }
        }
        return ans;
    }
};