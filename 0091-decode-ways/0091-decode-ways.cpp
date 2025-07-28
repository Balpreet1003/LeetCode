class Solution {
    vector<int>dp;
    int solve(string& s, int i){
        if(i>=s.length()){
            return 1;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int ans=0;
        if(s[i]!='0'){
            ans+=solve(s, i+1);
        }
        if(i<s.length()-1 && (s[i]=='1' || (s[i]=='2' && s[i+1]<'7'))){
            ans+=solve(s, i+2);
        }
        return dp[i] = ans;
    }
public:
    int numDecodings(string s) {
        dp.resize(s.length()+1,-1);
        return solve(s, 0);
    }
};