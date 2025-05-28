class Solution {
    vector<vector<int>>ans;
    vector<bool>visited;
    vector<int>temp;
    void solve(vector<int>&nums,int i){
        if(i>=nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int j=0;j<nums.size();j++){
            if(!visited[j]){
                temp.push_back(nums[j]);
                visited[j]=true;
                solve(nums,i+1);
                temp.pop_back();
                visited[j]=false;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        visited=vector<bool>(nums.size(),false);
        solve(nums,0);
        return ans; 
    }
};