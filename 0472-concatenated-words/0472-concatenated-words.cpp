class TriesNode {
public:
    TriesNode* children[26];
    bool isTerminal;

    TriesNode() {
        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
        isTerminal = false;
    }
};

class Tries {
    TriesNode* root;

public:
    Tries() {
        root = new TriesNode();
    }

    void insert(const string& word) {
        TriesNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx]) {
                node->children[idx] = new TriesNode();
            }
            node = node->children[idx];
        }
        node->isTerminal = true;
    }

    bool canForm(const string& word, int index, unordered_map<int, bool>& dp, int count) {
        if (dp.find(index) != dp.end())
            return dp[index];

        TriesNode* node = root;
        for (int i = index; i < word.size(); ++i) {
            int idx = word[i] - 'a';
            if (!node->children[idx])
                return dp[index] = false;
            node = node->children[idx];
            if (node->isTerminal) {
                if (i == word.size() - 1) {
                    return dp[index] = (count >= 1);
                }
                if (canForm(word, i + 1, dp, count + 1)) {
                    return dp[index] = true;
                }
            }
        }
        return dp[index] = false;
    }
};

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.length() < b.length();
        });

        Tries t;
        vector<string> ans;

        for (const string& word : words) {
            if (word.empty()) continue;

            unordered_map<int, bool> dp;
            if (t.canForm(word, 0, dp, 0)) {
                ans.push_back(word);
            } else {
                t.insert(word);
            }
        }

        return ans;
    }
};