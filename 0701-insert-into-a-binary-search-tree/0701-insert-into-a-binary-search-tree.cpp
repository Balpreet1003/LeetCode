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
    TreeNode*solve(TreeNode*root,int&t){
        if(!root){
            return new TreeNode(t);
        }
        if(root->val>t)root->left=solve(root->left,t);
        else root->right=solve(root->right,t);
        return root;
    }
public:
    TreeNode* insertIntoBST(TreeNode* root, int t) {
        return solve(root,t);
    }
};