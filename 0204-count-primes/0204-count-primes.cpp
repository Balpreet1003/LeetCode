class Solution {
public:
    int countPrimes(int n) {
        if(n==0 || n==1)
            return 0;
        vector<bool>isPrime(n,true);
        for(int i=2;i<n;i++){
            if(isPrime[i]){
                for(long long j=i*1LL*i;j<n;j+=i){
                    isPrime[j]=false;
                }
            }
        }
        int ans=0;
        for(int i=2;i<n;i++)
            if(isPrime[i])ans++;
        return ans;
    }
};