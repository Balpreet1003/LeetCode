class Solution {
public:
    bool isCircularSentence(string s) {
        bool ans = true;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                if (s[i - 1] != s[i + 1])
                    return false;
            }
        }
        return (s[0] == s[s.length() - 1]) && ans;
    }
};