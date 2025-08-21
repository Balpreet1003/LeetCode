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
    pair<TreeNode*, TreeNode*>getNode(TreeNode* root, int val){
        TreeNode* node=root, *prev=NULL;
        while(node){
            if(node->val==val)
                return {node, prev};
            prev=node;
            if(node->val<val)
                node=node->right;
            else
                node=node->left;
        }
        return {NULL, NULL};
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return root;

        if(root->val==key){
            TreeNode* node=root->left;
            if(!node)
                return root->right;

            while(node->right)
                node=node->right;
            
            node->right = root->right;
            return root->left;
        }

        auto [node, prev] = getNode(root, key);
        if(!node)
            return root;
        
        TreeNode* temp=node->left;
        if(!temp){
            if(prev->left==node) {
                prev->left=node->right;
            }
            else{
                prev->right=node->right;
            }
        }
        else{
            while(temp->right)
                temp=temp->right;
            
            if(prev->left==node)
                prev->left=node->left;
            else
                prev->right=node->left;
            
            temp->right=node->right;
            node->right=NULL;

        }
        return root;
    }
};