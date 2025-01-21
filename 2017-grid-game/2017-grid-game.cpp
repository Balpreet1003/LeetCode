class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<vector<long long>> a(2, vector<long long>(n));
        a[0][0] = 0;
        a[1][0] = grid[1][0];
        
        for (int i = 1; i < n; i++) {
            a[0][i] = a[0][i - 1] + grid[0][i];
            a[1][i] = a[1][i - 1] + grid[1][i];
        }
        
        a[1][n - 1] = 0;
        long long ans = LLONG_MAX;
        
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                ans = min(ans, a[0][n - 1]);
            } else if (i == n - 1) {
                ans = min(ans, a[1][n - 2]);
            } else {
                ans = min(ans, max(a[0][n - 1] - a[0][i], a[1][i - 1]));
            }
        }
        
        return ans;
    }
};