class Solution {
    vector<vector<int>> dp;
    bool solve(string &s, string &p, int i, int j) {
        if (j >= p.length()) return i >= s.length();
        if (dp[i][j] != -1) return dp[i][j];
        
        bool match = (i < s.length() && (s[i] == p[j] || p[j] == '.'));
        
        if (j+1 < p.length() && p[j+1] == '*') {
            return dp[i][j] = (solve(s, p, i, j+2) || (match && solve(s, p, i+1, j)));
        } else {
            return dp[i][j] = (match && solve(s, p, i+1, j+1));
        }
    }
public:
    bool isMatch(string s, string p) {
        dp.resize(s.length()+1, vector<int>(p.length()+1, -1));
        return solve(s, p, 0, 0);
    }
};