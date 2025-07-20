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
    unordered_map<TreeNode*, bool> m;
    unordered_map<TreeNode*, int> sum;
    unordered_map<TreeNode*, int> minMap;
    unordered_map<TreeNode*, int> maxMap;
    bool get_bst(TreeNode* root, int l, int r) {
        if (!root) return true;
        
        bool leftBST = get_bst(root->left, l, root->val);
        bool rightBST = get_bst(root->right, root->val, r);

        int leftMax = root->left ? maxMap[root->left] : INT_MIN;
        int rightMin = root->right ? minMap[root->right] : INT_MAX;

        bool isBST = leftBST && rightBST && root->val > leftMax && root->val < rightMin;

        m[root] = isBST;
        
        minMap[root] = root->left ? min(minMap[root->left], root->val) : root->val;
        maxMap[root] = root->right ? max(maxMap[root->right], root->val) : root->val;
        
        return isBST;
    }
    int get_sum_map(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int s1 = get_sum_map(root->left);
        int s2 = get_sum_map(root->right);
        return sum[root] = s1 + s2 + root->val;
    }
    int get_sum(TreeNode* root, int& ans) {
        if (!root) return 0;
        
        int leftMax = get_sum(root->left, ans);
        int rightMax = get_sum(root->right, ans);

        if (m[root]) {
            ans = max(ans, sum[root]);
        }

        return max({leftMax, rightMax, m[root] ? sum[root] : INT_MIN});
    }

public:
    int maxSumBST(TreeNode* root) {
        get_bst(root, INT_MIN, INT_MAX);
        get_sum_map(root);
        int ans = 0;
        get_sum(root, ans);
        return max(0, ans);
    }
};