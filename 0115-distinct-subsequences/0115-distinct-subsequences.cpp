class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.length(), m = t.length();
        vector<double> curr(m + 1, 0), prev(m + 1, 0);
        
        curr[0] = 1;
        prev[0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                double cnt = 0;
                if (s[i - 1] == t[j - 1])
                    cnt += prev[j - 1];
                curr[j] = cnt + prev[j];
            }
            prev = curr;
        }

        return curr[m];
    }
};