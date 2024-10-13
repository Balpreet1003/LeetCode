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
    int height(TreeNode* root){
        //base case
        if(root==NULL) return 0;
        
        //1 case
        int Lheight=height(root->left);
        int Rheight=height(root->right);
        int ans=max(Lheight,Rheight)+1;
        return ans;
    }
    bool isBalanced(TreeNode* root) {
        //base case
        if(root==NULL){
            return true;
        }
        //1 case
        int Lheight=height(root->left);
        int Rheight=height(root->right);
        int diff=abs(Lheight-Rheight);
        bool ans=(diff<=1);
        //RE
        bool Lans= isBalanced(root->left);
        bool Rans= isBalanced(root->right);
        if(Lans && Rans && ans) return true;
        else return false;
    }
};