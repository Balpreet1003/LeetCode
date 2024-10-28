class Solution {
public:
    int longestSquareStreak(vector<int>& a) {
        int n = a.size();
        if (n == 0) return -1;
        sort(a.begin(), a.end());
        unordered_map<int, int> dp;
        int ans = -1;
        for (int i = 0; i < n; ++i) {
            int curr = a[i];
            dp[curr] = 1; 
            if (curr == 1) continue;
            int prev = sqrt(curr);
            if (prev * prev == curr && dp.find(prev) != dp.end()) {
                dp[curr] = max(dp[curr], dp[prev] + 1);
            }
            ans = max(ans, dp[curr]);
        }
        return ans > 1 ? ans : -1;
    }
};