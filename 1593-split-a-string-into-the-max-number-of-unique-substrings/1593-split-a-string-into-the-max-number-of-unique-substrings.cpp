class Solution {
    unordered_set<string> m;
    int solve(string &s, int i) {
        if (i >= s.size()) return 0;

        int ans = 0;
        for (int j = i + 1; j <= s.size(); j++) {
            string t = s.substr(i, j - i);
            if (m.find(t) == m.end()) {
                m.insert(t);
                ans = max(ans, 1 + solve(s, j));
                m.erase(t);
            }
        }
        return ans;
    }
public:
    int maxUniqueSplit(string s) {
        return solve(s, 0);
    }
};