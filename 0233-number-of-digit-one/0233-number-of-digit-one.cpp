class Solution {
public:
    int countDigitOne(int n) {
        long long ans=0;
        for(long long i=1;i<=n;i*=10){
            long long div=i*10;
            long long q=n/div;
            long long rem=n%div;
            ans+=(q*i);
            if(rem>=i){
                ans+=min(rem-i+1,i);
            }
        }
        return ans;
    }
};