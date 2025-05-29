class Solution {
    set<vector<int>>ans;
    vector<int>temp;
    vector<bool>visited;
    void solve(vector<int>&nums){
        if(temp.size()==nums.size()){
            ans.insert(temp);
            return;
        }
        for(int j=0;j<nums.size();j++){
            if(!visited[j]){
                temp.push_back(nums[j]);
                visited[j]=true;

                solve(nums);

                temp.pop_back();
                visited[j]=false;
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        visited.resize(nums.size(),false);
        solve(nums);
        return vector<vector<int>>(ans.begin(),ans.end());
    }
};