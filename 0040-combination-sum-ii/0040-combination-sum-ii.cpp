class Solution {
    vector<vector<int>>ans;
    vector<int>temp;
private:
    void getCombination(vector<int>& nums,int target,int i){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(target<0)
            return;
        for(int k=i;k<nums.size();k++){
            if (k > i && nums[k] == nums[k - 1]) continue;
            if (nums[k] > target) break;
            temp.push_back(nums[k]);
            getCombination(nums,target-nums[k],k+1);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        getCombination(nums,target,0);
        return ans;
    }
};