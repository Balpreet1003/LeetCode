class Solution {
    vector<vector<double>> dp;

public:
    int numDistinct(string s, string t) {
        int n = s.length(), m = t.length();
        dp = vector<vector<double>>(n + 1, vector<double>(m + 1, 0));

        for (int i = 0; i <= n; i++)
            dp[i][m] = 1;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int cnt = 0;
                if (s[i] == t[j])
                    dp[i][j]= dp[i + 1][j + 1]+dp[i + 1][j];
                else dp[i][j] = dp[i + 1][j];
            }
        }

        return dp[0][0];
    }
};