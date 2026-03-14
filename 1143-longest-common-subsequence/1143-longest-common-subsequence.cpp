class Solution {
    vector<vector<int>>dp;
    int solve(string& s1, string& s2, int i, int j){
        if(i>=s1.length() || j>=s2.length())
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans=0;
        if(s1[i]==s2[j])
            ans=max(ans, solve(s1, s2, i+1, j+1)+1);
        ans=max({ans, solve(s1, s2, i+1, j), solve(s1, s2, i, j+1)});
        return dp[i][j]=ans;
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        dp.resize(text1.length()+1, vector<int>(text2.length()+1, -1));
        return solve(text1, text2, 0, 0);
    }
};