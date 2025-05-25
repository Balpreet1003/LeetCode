#define ll long long
class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        ll ans=0;
        while(n>k){
            n-=k;
            ans+=((ll)n*k);
        }
        while(m>k){
            m-=k;
            ans+=((ll)m*k);
        }
        return ans;
    }
};