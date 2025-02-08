class Solution {
    vector<vector<bool>>dp;
    bool solve(string&s,string &p, int i, int j){
        if(i<0 && j<0)return true;
        if(i<0 && j>=0){
            for(;j>=0;j--){
                if(p[j]!='*')return false;
            }
            return true;
        }
        if(i>=0 && j<0)return false;

        if(dp[i][j]!=false)return dp[i][j];

        if(s[i]==p[j] || p[j]=='?')return dp[i][j] = solve(s,p,i-1,j-1);
        else if(p[j]=='*')return dp[i][j] = solve(s,p,i-1,j) || solve(s,p,i,j-1);
        else return dp[i][j] = false;
    }
public:
    bool isMatch(string s, string p) {
        int n=s.length(),m=p.length();
        dp=vector<vector<bool>>(n+1,vector<bool>(m+1,false));
        return solve(s,p,n-1,m-1);
    }
};