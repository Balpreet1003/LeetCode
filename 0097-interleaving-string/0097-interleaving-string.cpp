class Solution {
    int n1, n2, m;
    vector<vector<vector<int>>> dp;
    // bool solve(string& s1, string& s2, string& s3, int k, int i, int j) {
    //     if (k == m)
    //         return true;
    //     if (dp[k][i][j] != -1)
    //         return dp[k][i][j];

    //     bool ans = false;
    //     if (i < n1 && s3[k] == s1[i])
    //         ans |= solve(s1, s2, s3, k + 1, i + 1, j);
    //     if (j < n2 && s3[k] == s2[j])
    //         ans |= solve(s1, s2, s3, k + 1, i, j + 1);
    //     return dp[k][i][j] = ans;
    // }

public:
    bool isInterleave(string s1, string s2, string s3) {
        n1 = s1.length();
        n2 = s2.length();
        m = s3.length();
        if (n1 + n2 != m)
            return false;
        dp.resize(m + 1, vector<vector<int>>(n1 + 1, vector<int>(n2 + 1, 0)));
        // vector<vector<int>>prev(n1+1, vector<int>(n2+1, false)), curr(n1+1, vector<int>(n2+1, false))
        dp[m][n1][n2]=true;
        for(int k=m-1;k>=0;k--){
            for(int i=n1;i>=0;i--){
                for(int j=n2;j>=0;j--){
                    bool ans = false;
                    if (i < n1 && s3[k] == s1[i])
                        ans |= dp[k + 1][i + 1][j];
                    if (j < n2 && s3[k] == s2[j])
                        ans |= dp[k + 1][i][j + 1];
                    dp[k][i][j] = ans;
                }
            }
        }
        return dp[0][0][0];
    }
};