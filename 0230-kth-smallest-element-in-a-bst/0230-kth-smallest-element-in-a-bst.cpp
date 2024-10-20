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
public:
    int kthSmallest(TreeNode* root, int& k) {
        //base case
        if(root==NULL)
            return -1;
        
        //left
        int Lans=kthSmallest(root->left,k);
        if(Lans!=-1)
            return Lans;
        //node
        k--;
        if(k==0)
            return root->val;
        //right
        return kthSmallest(root->right,k);
    }
};