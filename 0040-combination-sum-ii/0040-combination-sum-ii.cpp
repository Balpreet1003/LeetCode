class Solution {
private:
    void getCombination(vector<int>& nums,int target,vector<vector<int>>&ans,vector<int>&temp,int i){
        //bc
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(target<0)
            return;

        //1 case
        for(int k=i;k<nums.size();k++){
            if (k > i && nums[k] == nums[k - 1]) continue;
            if (nums[k] > target) break;
            temp.push_back(nums[k]);
            getCombination(nums,target-nums[k],ans,temp,k+1);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>temp;
        getCombination(nums,target,ans,temp,0);
        return ans;
    }
};