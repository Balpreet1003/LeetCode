class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        vector<int> first(26, -1), last(26, -1);
        unordered_set<string> uniquePalindromes;

        // Record first and last occurrence of each character
        for (int i = 0; i < n; ++i) {
            if (first[s[i] - 'a'] == -1) {
                first[s[i] - 'a'] = i;
            }
            last[s[i] - 'a'] = i;
        }

        int count = 0;

        // For each character, calculate unique middle characters
        for (char c = 'a'; c <= 'z'; ++c) {
            int f = first[c - 'a'];
            int l = last[c - 'a'];
            if (f != -1 && f + 1 < l) {
                unordered_set<char> middleChars;
                for (int i = f + 1; i < l; ++i) {
                    middleChars.insert(s[i]);
                }
                count += middleChars.size();
            }
        }

        return count;
    }
};