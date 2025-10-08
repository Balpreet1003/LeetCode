class Solution {
    int n1, n2, m;
    vector<vector<vector<int>>> dp;
    bool solve(string& s1, string& s2, string& s3, int k, int i, int j) {
        if (k == m)
            return true;
        if (dp[k][i][j] != -1)
            return dp[k][i][j];

        bool ans = false;
        if (i < n1 && s3[k] == s1[i])
            ans |= solve(s1, s2, s3, k + 1, i + 1, j);
        if (j < n2 && s3[k] == s2[j])
            ans |= solve(s1, s2, s3, k + 1, i, j + 1);
        return dp[k][i][j] = ans;
    }

public:
    bool isInterleave(string s1, string s2, string s3) {
        n1 = s1.length();
        n2 = s2.length();
        m = s3.length();
        if (n1 + n2 != m)
            return false;
        dp.resize(m + 1, vector<vector<int>>(n1 + 1, vector<int>(n2 + 1, -1)));
        return solve(s1, s2, s3, 0, 0, 0);
    }
};

// class Solution {
//     int n1, n2, m;
//     vector<vector<vector<int>>> dp;

//     bool solve(string& s1, string& s2, string& s3, int k, int i, int j) {
//         if (k == m)
//             return true;
//         if (dp[k][i][j] != -1)
//             return dp[k][i][j];

//         bool ok = false;
//         if (i < n1 && s3[k] == s1[i])
//             ok = ok || solve(s1, s2, s3, k + 1, i + 1, j);
//         if (j < n2 && s3[k] == s2[j])
//             ok = ok || solve(s1, s2, s3, k + 1, i, j + 1);

//         return dp[k][i][j] = ok;
//     }

// public:
//     bool isInterleave(string s1, string s2, string s3) {
//         n1 = s1.length();
//         n2 = s2.length();
//         m = s3.length();

//         if (n1 + n2 != m)
//             return false; // basic length mismatch check

//         dp.assign(m + 1, vector<vector<int>>(n1 + 1, vector<int>(n2 + 1, -1)));
//         return solve(s1, s2, s3, 0, 0, 0);
//     }
// };
