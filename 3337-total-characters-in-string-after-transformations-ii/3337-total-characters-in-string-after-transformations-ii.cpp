class Solution {
    const int mod=1000000007;
public:
    int lengthAfterTransformations(string s, int t, vector<int>& a) {
        vector<int>b(26,0);
        for(char c:s)b[c-'a']++;
        for(int i=0;i<t;i++){
            vector<int>c(26,0);
            for(int j=0;j<26;j++){
                for(int k=a[j];k>0;k--){
                    c[(j+k)%26]=(c[(j+k)%26]+b[j])%mod;
                }
            }
            b=c;
        }
        int ans=0;
        for(int i:b)ans=(ans+i)%mod;
        return ans;
    }
};