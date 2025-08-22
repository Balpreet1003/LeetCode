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
    bool is_poss(TreeNode* root, int tar, TreeNode* node){
        TreeNode* curr = root;
        while(curr){
            if(curr->val==tar){
                if(curr==node)
                    return false;
                return true;
            }
            if(curr->val>tar)
                curr=curr->left;
            else
                curr=curr->right;
        }
        return false;
    }
public:
    bool findTarget(TreeNode* root, int k) {
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            if(is_poss(root, k-node->val, node))
                return true;
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        return false;
    }
};