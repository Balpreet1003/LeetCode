#define vi vector
class Solution {
    const int MOD = 1e9+7;
    vi<vi<vi<int>>> dp;

    int solve(int m, int n, int k, int maxi){
        if(n == 0)
            return k == 0;

        if(k < 0)
            return 0;

        if(dp[n][k][maxi] != -1)
            return dp[n][k][maxi];

        long long ans = 0;

        // case 1: pick value ≤ current max
        if(maxi > 0)
            ans = (ans + (long long)maxi * solve(m, n-1, k, maxi) % MOD) % MOD;

        // case 2: pick value > current max
        for(int i = maxi + 1; i <= m; i++){
            ans = (ans + solve(m, n-1, k-1, i)) % MOD;
        }

        return dp[n][k][maxi] = ans;
    }

public:
    int numOfArrays(int n, int m, int k) {
        dp.assign(n+1, vi<vi<int>>(k+1, vi<int>(m+1, -1)));
        return solve(m, n, k, 0);
    }
};