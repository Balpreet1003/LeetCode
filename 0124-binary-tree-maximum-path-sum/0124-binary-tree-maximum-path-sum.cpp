/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    pair<int, int> solve(TreeNode* root) {
        if (!root) return {INT_MIN, 0}; 

        auto x = solve(root->left);
        auto y = solve(root->right);
        int a = max(x.second, 0) + max(y.second, 0) + root->val;
        int b = max(max(x.second, y.second), 0) + root->val;
        int c = max({x.first, y.first, a});

        return {c, b};
    }

public:
    int maxPathSum(TreeNode* root) {
        auto result = solve(root);
        return result.first;
    }
};