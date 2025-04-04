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
    unordered_map<TreeNode*,int>m;
    int getHeight(TreeNode*root){
        if(!root)return 0;
        int l=getHeight(root->left)+1;
        int r=getHeight(root->right)+1;
        m[root]=max(l,r);
        return max(l,r);
    }
    TreeNode* solve(TreeNode*root){
        if(!root->left && !root->right)return root;
        if(!root)return NULL;

        if(m[root->left]==m[root->right])return root;
        if(m[root->left]>m[root->right])return solve(root->left);
        return solve(root->right);
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        getHeight(root);
        return solve(root);
    }
};