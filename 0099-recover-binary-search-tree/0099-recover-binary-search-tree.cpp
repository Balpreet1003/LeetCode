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
    TreeNode* first, *second, *middle, *prev;
    void inorder(TreeNode* root){
        if(!root)
            return;
        inorder(root->left);
        if(prev && prev->val>root->val){
            if(!first){
                first=prev;
                middle=root;
            }
            else
                second=root;
        }
        prev=root;
        inorder(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        first=second=middle=NULL; 
        prev=new TreeNode(INT_MIN);
        inorder(root);
        if(first && second)swap(first->val, second->val);
        else if(first && middle)swap(first->val, middle->val);
    }
};