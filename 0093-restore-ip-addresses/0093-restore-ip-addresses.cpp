class Solution {
    vector<string> ans;

    void solve(string& s, string s1, int i, int cnt) {
        if (cnt > 4) return;  // only 4 parts allowed
        if (cnt == 4 && i == s.length()) {
            s1.pop_back(); // remove last '.'
            ans.push_back(s1);
            return;
        }
        int x = 0;
        for (int j = i; j < s.length() && j < i+3; j++) {
            x = x * 10 + (s[j] - '0');
            if (x > 255) break;
            if (j > i && s[i] == '0') break;

            solve(s, s1 + s.substr(i, j-i+1) + ".", j+1, cnt+1);
        }
    }

public:
    vector<string> restoreIpAddresses(string s) {
        if (s.length() < 4 || s.length() > 12) return {};
        solve(s, "", 0, 0);
        return ans;
    }
};