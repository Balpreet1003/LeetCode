class TriesNode {
public:
    char val;
    TriesNode* children[26];
    bool isTerminal;

    TriesNode(char val) {
        this->val = val;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Solution {
    class Tries {
        TriesNode* root;
        vector<string>& ans;

        void insertUtil(TriesNode* root, string& s) {
            TriesNode* node = root;
            for (int i = 0; i < s.length(); i++) {
                int ind = s[i] - 'a';
                if (!node->children[ind]) {
                    node->children[ind] = new TriesNode(s[i]);
                }
                node = node->children[ind];
            }
            node->isTerminal = true;
        }

        void searchUtil(TriesNode* node, vector<vector<char>>& board, int i, int j, string s) {
            if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] == '@')
                return;

            char ch = board[i][j];
            int ind = ch - 'a';

            if (!node->children[ind]) return;

            node = node->children[ind];
            s += ch;

            if (node->isTerminal) {
                ans.push_back(s);
                node->isTerminal = false; // Avoid duplicates
            }

            board[i][j] = '@'; // mark visited

            searchUtil(node, board, i + 1, j, s);
            searchUtil(node, board, i - 1, j, s);
            searchUtil(node, board, i, j + 1, s);
            searchUtil(node, board, i, j - 1, s);

            board[i][j] = ch; // unmark
        }

    public:
        Tries(vector<string>& ansRef) : root(new TriesNode('\0')), ans(ansRef) {}

        void insert(vector<string>& words) {
            for (string& word : words) {
                insertUtil(root, word);
            }
        }

        void search(vector<vector<char>>& board) {
            int n = board.size(), m = board[0].size();
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    searchUtil(root, board, i, j, "");
                }
            }
        }
    };

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        Tries t(ans);
        t.insert(words);
        t.search(board);
        return ans;
    }
};