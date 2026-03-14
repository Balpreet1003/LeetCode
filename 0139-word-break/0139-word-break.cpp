class Solution {
    unordered_map<string, int>mp;
    vector<int>dp;
    bool solve(string& s, int i){
        if(i>=s.length())
            return true;
        if(dp[i]!=-1)
            return dp[i];
        bool ans=false;
        string s1="";
        for(int j=i;j<s.length();j++){
            s1+=s[j];
            if(mp.count(s1)){
                ans|=solve(s, j+1);
                if(ans)
                    return dp[i]=ans;
            }  
        }
        return dp[i]=false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto x:wordDict)
            mp[x]=1;
        dp.resize(s.length()+1, -1);
        return solve(s, 0);
    }
};