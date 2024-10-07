class Solution {
    const long long mod=1000000007;
    long long solve(long long n){
        if(n==0)return 1;
        if(!(n&1)){
            int a=solve(n/2);
            return ((long long)a*a)%mod;
        }
        return ((long long)solve(n-1)*20)%mod;
    }
public:
    int countGoodNumbers(long long n) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        long long x=solve(n/2);
        if(n&1)return (x*5)%mod;
        return (x)%mod;
    }
};