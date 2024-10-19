/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    void dfs(TreeNode* root, string& s) {
        if (!root) {
            s += "#,";
            return;
        }
        s += to_string(root->val) + ",";
        dfs(root->left, s);
        dfs(root->right, s);
    }

    string serialize(TreeNode* root) {
        string s = "";
        dfs(root, s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* recover(string& s, int& i) {
        if (s[i] == '#') {
            i += 2; // Skip '#,' for null nodes
            return nullptr;
        }
        int x = 0;
        bool isNegative = false;
        // Handle potential negative numbers
        if (s[i] == '-') {
            isNegative = true;
            i++;
        }
        while (isdigit(s[i])) {
            x = (x * 10) + (s[i] - '0');
            i++;
        }
        if (isNegative) {
            x = -x;
        }
        i++; // Skip the comma
        TreeNode* node = new TreeNode(x);
        node->left = recover(s, i);
        node->right = recover(s, i);
        return node;
    }

    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        int i = 0;
        return recover(data, i);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));