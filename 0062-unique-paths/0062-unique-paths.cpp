class Solution {
public:
    int uniquePaths(int m, int n) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<int> dp(n, 1); 
        for(int i = m - 2; i >= 0; i--) { 
            for(int j = n - 2; j >= 0; j--) { 
                dp[j] = dp[j] + dp[j + 1]; 
            }
        }
        return dp[0];
    }
};