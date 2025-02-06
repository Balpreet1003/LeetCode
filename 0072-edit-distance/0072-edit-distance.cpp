class Solution {
    vector<vector<long long>>dp;
    int solve(string&s,string&t,int i,int j){
        if(i==s.length())return t.length()-j;
        if(j==t.length())return s.length()-i;

        if(dp[i][j]!=-1)return dp[i][j];

        if(s[i]==t[j])  return dp[i][j] = solve(s,t,i+1,j+1);
        return dp[i][j] = min(solve(s,t,i+1,j),min(solve(s,t,i,j+1),solve(s,t,i+1,j+1)))+1;
    }
public:
    int minDistance(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        dp=vector<vector<long long>>(n+1,vector<long long>(m+1,-1));

        for(int j=0;j<=m;j++)dp[n][j]=m-j;
        for(int i=0;i<=n;i++)dp[i][m]=n-i;

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(word1[i]==word2[j]) dp[i][j] = dp[i+1][j+1];
                else dp[i][j] = min(dp[i+1][j],min(dp[i][j+1],dp[i+1][j+1]))+1;
            }
        }
        
        return dp[0][0];
    }
};