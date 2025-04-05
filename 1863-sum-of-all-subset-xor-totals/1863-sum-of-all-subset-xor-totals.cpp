class Solution {
    int ans=0;
    void solve(vector<int>&nums,int x,int i){
        if(i>=nums.size()){
            ans+=x;
            return ;
        }

        solve(nums,x^nums[i],i+1);
        solve(nums,x,i+1);
    }
public:
    int subsetXORSum(vector<int>& nums) {
        solve(nums,0,0);
        return ans;
    }
};