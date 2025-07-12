class Solution {
    unordered_map<string,int>dp;
    bool solve(string s1,string s2){
        int n=s1.length();
        if(s1.length()==1){
            return s1==s2;
        }
        if(s1==s2){
            return true;
        }
        string key=s1+"/"+s2;
        if(dp.count(key)){
            return dp[key];
        }
        for(int i=1;i<n;i++){
            if((solve(s1.substr(0,i),s2.substr(0,i)) && solve(s1.substr(i),s2.substr(i))) || (solve(s1.substr(0,i),s2.substr(n-i)) && solve(s1.substr(i),s2.substr(0,n-i)))){
                return dp[key] = true;
            }
        }
        return dp[key] = false;
    }
public:
    bool isScramble(string s1, string s2) {
        return solve(s1,s2);
    }
};