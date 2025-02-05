class Solution {
    vector<vector<int>>dp;
    int solve(string& s,int i,int j){
        if(i>=j)return 0;

        if(dp[i][j]!=-1)return dp[i][j];

        if(s[i]==s[j]) return dp[i][j] = solve(s,i+1,j-1);
        return dp[i][j] = min(solve(s,i+1,j),solve(s,i,j-1))+1;
    }
public:
    int minInsertions(string s) {
        int n=s.length();
        dp=vector<vector<int>>(n+1,vector<int>(n+1,-1));
        return solve(s,0,s.length()-1);
    }
};