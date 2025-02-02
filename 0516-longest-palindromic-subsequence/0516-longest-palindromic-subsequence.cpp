class Solution {
    vector<vector<int>>dp;
public:
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        dp=vector<vector<int>>(n+1,vector<int>(n+1,0));
        string t=s;
        reverse(s.begin(),s.end());
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int ans=0;
                if(s[i]==t[j])ans=dp[i+1][j+1]+1;
                dp[i][j] = max(ans,max(dp[i+1][j],dp[i][j+1]));
            }
        }
        return dp[0][0];
    }
};