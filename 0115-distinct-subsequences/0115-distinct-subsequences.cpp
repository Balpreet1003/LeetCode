class Solution {
    vector<vector<int>> dp;
    int solve(string& s, string& t, int i, int j) {
        if (j >= t.length())
            return 1;
        if (i >= s.length())
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int cnt = 0;
        if (s[i] == t[j])
            cnt += solve(s, t, i + 1, j + 1);
        return dp[i][j] = cnt + solve(s, t, i + 1, j);
    }

public:
    int numDistinct(string s, string t) {
        int n = s.length(), m = t.length();
        dp = vector<vector<int>>(n + 1, vector<int>(m + 1, -1));

        // for (int i = 0; i <= n; i++)
        //     dp[i][m] = 1;

        // for (int i = n - 1; i >= 0; i--) {
        //     for (int j = m - 1; j >= 0; j--) {
        //         int cnt = 0;
        //         if (s[i] == t[j])
        //             cnt += dp[i + 1][j + 1];
        //         dp[i][j] = cnt + dp[i + 1][j];
        //     }
        // }

        return solve(s,t,0,0);
    }
};