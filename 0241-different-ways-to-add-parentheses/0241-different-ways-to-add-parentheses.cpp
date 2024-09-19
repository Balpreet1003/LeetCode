class Solution {
    vector<int>solve(string s, unordered_map<string,vector<int>>&dp){
        if(dp.find(s)!=dp.end())return dp[s];
        vector<int>ans;
        for(int i=0;i<s.length();i++){
            if(s[i]=='+' || s[i]=='*' || s[i]=='-'){
                vector<int>left,right;
                left=solve(s.substr(0,i),dp);
                right=solve(s.substr(i+1),dp);

                for(int j:left){
                    for(int k:right){
                        if(s[i]=='+')ans.push_back(j+k);
                        else if(s[i]=='*')ans.push_back(j*k);
                        else ans.push_back(j-k);
                    }
                }
            }
        }
        if(ans.empty())ans.push_back(stoi(s));
        return dp[s]=ans;
    }
public:
    vector<int> diffWaysToCompute(string s) {
        unordered_map<string,vector<int>>dp;
        return solve(s,dp);
    }
};