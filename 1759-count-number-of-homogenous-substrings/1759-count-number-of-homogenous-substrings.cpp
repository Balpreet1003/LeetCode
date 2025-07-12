class Solution {
    const int MOD=1e9+7;
public:
    int countHomogenous(string s) {
        int len=1,ans=0;
        for(int i=1;i<s.length();i++){
            if(s[i-1]==s[i]){
                len++;
            }
            else{
                long long cnt=(((1LL*(len+1)*len))/2)%MOD;
                ans=(ans+cnt)%MOD;
                len=1;
            }
        }
        long long cnt=(((1LL*(len+1)*len))/2)%MOD;
        ans=(ans+cnt)%MOD;
        return ans;
    }
};