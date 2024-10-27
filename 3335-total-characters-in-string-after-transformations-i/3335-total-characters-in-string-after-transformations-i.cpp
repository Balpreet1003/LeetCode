class Solution {
    const int mod=1000000007;
public:
    int lengthAfterTransformations(string s, int t) {
        int ans=0;
        vector<int>a(26,0);
        for(char c:s) a[c-'a']++;
        for(int i=0;i<t;i++){
            vector<int>b(26,0);
            for(int j=0;j<26;j++){
                if(j==25){
                    b[0] = (b[0] + a[j]) % mod;
                    b[1] = (b[1] + a[j]) % mod;
                }
                else {
                    b[j+1]=(b[j+1]+a[j]) % mod;
                }
            }
            a=b;
        }
        for(int i:a){
            ans=(ans+i) % mod;
        }
        return ans;
    }
};