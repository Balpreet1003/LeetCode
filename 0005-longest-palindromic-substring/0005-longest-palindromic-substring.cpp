class Solution {
private:
    bool isPalindrom(string & s,int i,int j,vector<vector<int>>& dp){
        //bc
        if(i>=j){
            return true;
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        //1 case
        dp[i][j]= s[i]==s[j] ? isPalindrom(s,i+1,j-1,dp): false;
        return dp[i][j];
    }
public:
    string longestPalindrome(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int n=s.length();
        string ans="";
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(ans.length()<(j-i+1) && isPalindrom(s,i,j,dp)){
                    ans=s.substr(i,j-i+1);
                }
            }
        }
        return ans;
    }
};