class Solution {
    bool is_poss(string&s1,string&s2){
        int n=s1.length(), m=s2.length();
        if(n-m!=1)return false;
        int i=0,j=0, cnt=0;
        while(i<n && j<m){
            if(s1[i]!=s2[j]){
                cnt++;
                i++;
            }
            else{
                i++;j++;
            }
        }
        cnt+=(n-i);
        return cnt==1;
    }
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string &a, const string &b){
            return a.length() < b.length();
        });
        int n=words.size(), maxi=1;
        vector<int>dp(n,1);
        for(int i=0;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(is_poss(words[i],words[j])){
                    dp[i]=max(dp[i],dp[j]+1);
                    maxi=max(maxi,dp[i]);
                }
            }
        }
        return maxi;
    }
};