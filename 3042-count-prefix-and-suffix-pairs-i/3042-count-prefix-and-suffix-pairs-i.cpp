class Solution {
    bool isPoss(string &s1, string &s2) {
        if (s1.length() > s2.length()) return false;

        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i]) return false;
        }

        int len1 = s1.length(), len2 = s2.length();
        for (int i = 0; i < len1; i++) {
            if (s1[len1 - 1 - i] != s2[len2 - 1 - i]) return false;
        }
        return true;
    }

public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans = 0, n = words.size();
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) { // Compare all pairs, including reversed positions
                if (i != j && isPoss(words[i], words[j])) {
                    ans++;
                }
            }
        }
        return ans;
    }
};