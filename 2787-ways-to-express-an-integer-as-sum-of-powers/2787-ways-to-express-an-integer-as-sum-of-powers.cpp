class Solution {
    const int MOD=1e9+7;
public:
    int numberOfWays(int n, int x) {
        vector<int>prev(n+1,0), curr(n+1,0);
        prev[0]=1;
        curr[0]=1;
        for(int i=1;i<=n;i++){
            for(int sum=1;sum<=n;sum++){
                int ans=0;
                if(sum-pow(i, x)>=0){
                    ans=(ans+prev[sum-pow(i, x)])%MOD;
                }
                curr[sum]=(prev[sum] + ans)%MOD;
            }
            prev=curr;
        }
        return curr[n]; 
    }
};