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
    bool solve(TreeNode*a,TreeNode*b){
        if(!a && !b)return 1;
        if(!a || !b)return 0;

        if(a->val != b->val)return 0;
        return solve(a->left,b->right) & solve(a->right,b->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return solve(root->left,root->right);
    }
};