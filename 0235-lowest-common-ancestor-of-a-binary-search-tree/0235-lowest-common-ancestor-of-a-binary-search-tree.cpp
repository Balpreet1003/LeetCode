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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val>q->val){
            swap(p,q);
        }
        TreeNode* node=root;
        while(node){
            if((node->val>p->val && node->val<q->val) || node->val==p->val || node->val==q->val)
                return node;
            if(node->val>p->val && node->val>q->val)
                node=node->left;
            else
                node=node->right;
        }
        return NULL;
    }
};