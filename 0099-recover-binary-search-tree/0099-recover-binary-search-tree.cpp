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
    vector<TreeNode*> a;
    
    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        a.push_back(root);
        inorder(root->right);
    }
    
public:
    void recoverTree(TreeNode* root) {
        inorder(root);
        TreeNode* first = nullptr;
        TreeNode* second = nullptr;        
        for (int i = 0; i < a.size() - 1; ++i) {
            if (a[i]->val > a[i + 1]->val) {
                if (!first) {
                    first = a[i];
                }
                second = a[i + 1]; 
            }
        }        
        if (first && second) {
            swap(first->val, second->val);
        }
    }
};