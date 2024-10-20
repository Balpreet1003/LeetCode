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
    TreeNode* solve(TreeNode* root, int t) {
        if (!root) return NULL;
        if (root->val == t) {
            if (!root->right) return root->left;
            if (!root->left) return root->right;            
            TreeNode* node = root->right;
            while (node->left) {
                node = node->left;
            }
            root->val = node->val;
            root->right = solve(root->right, node->val);
        } 
        else if (root->val > t) {
            root->left = solve(root->left, t);
        } 
        else {
            root->right = solve(root->right, t);
        }
        return root;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int t) {
        return solve(root, t);
    }
};