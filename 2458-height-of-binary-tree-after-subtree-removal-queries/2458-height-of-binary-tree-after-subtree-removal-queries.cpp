/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    unordered_map<TreeNode*, int> m1;
    unordered_map<int, int> m2;
    int solve1(TreeNode* root) {
        if (!root)
            return -1;
        m1[root] = max(solve1(root->left), solve1(root->right)) + 1;
        return m1[root];
    }
    void solve2(TreeNode* root, int x, int& maxi, int prev, bool trace) {
        if (!root)
            return;

        int l = (root->left) ? m1[root->left] + 1 + x : x;
        int r = (root->right) ? m1[root->right] + 1 + x : x;

        if (root->left && l == maxi)
            solve2(root->left, x + 1, maxi, max(r, prev), true);
        else
            solve2(root->left, x + 1, maxi, max(r, prev), false);
        if (root->right && r == maxi)
            solve2(root->right, x + 1, maxi, max(l, prev), true);
        else
            solve2(root->right, x + 1, maxi, max(l, prev), false);

        m2[root->val] = trace ? prev : maxi;
    }

public:
    vector<int> treeQueries(TreeNode* root, vector<int>& q) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        vector<int> ans;
        int x = solve1(root);
        solve2(root, 0, x, -1, true);
        for (int i : q) {
            ans.push_back(m2[i]);
        }
        return ans;
    }
};