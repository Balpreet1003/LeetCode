class Solution {
    const int MOD = 1e9+7;
public:
    int numSub(string s) {
        int cnt=0, ans=0;
        for(char c:s){
            if(c=='1'){
                cnt++;
            }
            else{
                ans=(ans+(((1LL*cnt*(cnt+1)%MOD))/2))%MOD;
                cnt=0;
            }
        }
        ans+=((cnt*(cnt+1))/2);
        return ans;
    }
};