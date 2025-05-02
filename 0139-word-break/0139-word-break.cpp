class Solution { 
    vector<int>dp;
    bool solve(string&s,unordered_map<string,bool>&m,int i){
        if(i>=s.length()){
            return true;
        }

        if(dp[i]!=-1)return dp[i];

        string s1="";
        bool ans=false;
        for(int j=i;j<s.length();j++){
            s1+=s[j];
            if(m.find(s1)!=m.end()){
                ans = ans || solve(s,m,j+1);
            }
        }
        return dp[i] = ans;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,bool>m;
        for(auto i:wordDict)m[i]=false;
        
        dp=vector<int>(s.length()+1,-1);

        return solve(s,m,0);
    }
};