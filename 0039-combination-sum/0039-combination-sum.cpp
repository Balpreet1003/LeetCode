class Solution {
public:
    void getCombination(vector<int>& nums, int target,vector<vector<int>>&ans,vector<int>&temp,int k){
        //bc
        if(target==0){
            ans.push_back(temp);
            return ;
        }
        if(target<0)
            return ;

        //1 case
        for(int i=k;i<nums.size();i++){
            temp.push_back(nums[i]);
            getCombination(nums,target-nums[i],ans,temp,i);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        int k=0;
        getCombination(candidates,target,ans,temp,k);
        return ans;
    }
};