class Solution {
    class TrieNode {
    public:
        TrieNode* children[26];
        bool isTerminal;

        TrieNode() {
            for (int i = 0; i < 26; i++) children[i] = NULL;
            isTerminal = false;
        }
    };

    TrieNode* root;

    // Function to add words to the Trie
    void addStr(string& s) {
        TrieNode* node = root;
        for (char ch : s) {
            int index = ch - 'a';
            if (!node->children[index])
                node->children[index] = new TrieNode();
            node = node->children[index];
        }
        node->isTerminal = true;
    }

    // DP + Trie search to minimize extra characters
    int minExtraCharDP(string& s, vector<string>& dictionary) {
        int n = s.size();
        vector<int> dp(n + 1, n);  // DP array to store min extra characters
        dp[0] = 0;

        // Iterate over all possible start positions
        for (int i = 0; i < n; i++) {
            // Start with current dp state
            TrieNode* node = root;
            for (int j = i; j < n; j++) {
                int index = s[j] - 'a';
                if (!node->children[index])
                    break;  // No match, break early
                node = node->children[index];
                if (node->isTerminal) {
                    dp[j + 1] = min(dp[j + 1], dp[i]);
                }
            }
            dp[i + 1] = min(dp[i + 1], dp[i] + 1);  // Add 1 if not matched
        }

        return dp[n];
    }

public:
    int minExtraChar(string s, vector<string>& dictionary) {
        root = new TrieNode();
        // Add all dictionary words to the Trie
        for (string& word : dictionary) {
            addStr(word);
        }
        return minExtraCharDP(s, dictionary);
    }
};