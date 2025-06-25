class Solution {
    bool is_palindrome(string& s){
        int i=0,j=s.length()-1;
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;j--;
        }
        return true;
    }
    unordered_map<string,int>dp;
    int solve(string& s,string s1,int i){
        if(i>=s.length()){
            if(is_palindrome(s1))
                return 0;
            return INT_MAX;
        }
        string key=to_string(i)+"/"+s1;
        if(dp.find(key)!=dp.end()){
            return dp[key];
        }
        int ans=INT_MAX;
        ans= min(ans,solve(s,s1+s[i],i+1));
        if(is_palindrome(s1)){
            s1="";
            ans=min(ans,solve(s,s1+s[i],i+1)+1);
        }
        return dp[key]=ans;
    }
public:
    int minCut(string s) {
        int n=s.length();
        vector<vector<bool>>pal(n,vector<bool>(n,false));
        for(int i=0;i<n;i++)pal[i][i]=true;
        for(int i=0;i<n-1;i++)pal[i][i+1]=(s[i]==s[i+1]);

        for(int l=3;l<=n;l++){
            for(int i=0;i<=n-l;i++){
                pal[i][i+l-1]=(s[i]==s[i+l-1]) && pal[i+1][i+l-2];
            }
        }
        vector<int>dp(n,INT_MAX);
        for(int i=0;i<n;i++){
            if(pal[0][i]){
                dp[i]=0;
            }
            else{
                for(int j=0;j<i;j++){
                    if(pal[j+1][i]){
                        dp[i]=min(dp[i],dp[j]+1);
                    }
                }
            }
        }
        return dp[n-1];
    }
};