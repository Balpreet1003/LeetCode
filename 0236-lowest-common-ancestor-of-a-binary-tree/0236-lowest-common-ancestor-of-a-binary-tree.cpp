/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    vector<TreeNode*> path1, path2;    
    bool findPath(TreeNode* root, TreeNode* target, vector<TreeNode*>& path) {
        if (!root) return false;
        path.push_back(root);        
        if (root == target) return true;        
        if (findPath(root->left, target, path) || findPath(root->right, target, path)) {
            return true;
        }        
        path.pop_back();
        return false;
    }
    
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1, path2;        
        findPath(root, p, path1);
        findPath(root, q, path2);        
        int i = 0;
        while (i < path1.size() && i < path2.size() && path1[i] == path2[i]) i++;
        return path1[i - 1];
    }
};