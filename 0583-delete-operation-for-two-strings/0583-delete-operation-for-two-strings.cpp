class Solution {
    vector<vector<int>>dp;
    int solve(string&s, string&t ,int i,int j){
        if(i>=s.length() || j>=t.length()){
            return max(s.length()-i,t.length()-j);
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=INT_MAX;
        if(s[i]==t[j]) ans = solve(s,t,i+1,j+1);
        return dp[i][j] = min(ans,min(solve(s,t,i+1,j),solve(s,t,i,j+1))+1);
    }
public:
    int minDistance(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        dp=vector<vector<int>>(n+1,vector<int>(m+1,-1));
        
        // for(int i=n-1;i>=0;i--){
        //     for(int j=m-1;j>=0;j--){
        //         int ans=INT_MAX;
        //         if(word1[i]==word2[j]) ans = dp[i+1][j+1];
        //         dp[i][j] = min(ans,min(dp[i+1][j],dp[i][j+1])+1);
        //     }
        // }

        return solve(word1,word2,0,0);
    }
};