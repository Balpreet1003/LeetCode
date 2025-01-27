class Solution {
    unordered_map<int,vector<int>>adjList;
    vector<vector<int>>dp;
    bool dfs(int target, int val) {
        if (dp[val][target] != -1) return dp[val][target];
        for (int i : adjList[val]) {
            if (i == target || dfs(target, i)) {
                return dp[val][target] = true;
            }
        }
        return dp[val][target] = false;
    }
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        for(auto i:prerequisites){
            adjList[i[1]].push_back(i[0]);
        }
        vector<bool>ans;
        dp=vector<vector<int>>(numCourses+1,vector<int>(numCourses+1,-1));
        for(auto i:queries){
            ans.push_back(dfs(i[0],i[1]));
        }
        return ans;
    }
};