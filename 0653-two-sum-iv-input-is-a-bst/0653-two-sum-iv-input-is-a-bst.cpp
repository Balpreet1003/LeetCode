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

    void InorderArray(TreeNode*root,vector<int>&inorder){
        //base case
        if(root==NULL)
            return;
        //1 case
        //left
        InorderArray(root->left,inorder);
        //node
        inorder.push_back(root->val);
        //right
        InorderArray(root->right,inorder);
    }

    bool findTarget(TreeNode* root, int& k) {
        //create inorder array
        vector<int>inorder;
        InorderArray(root,inorder);

        int s=0;
        int e=inorder.size()-1;
        while(s<e){
            int a=inorder[s], b=inorder[e];
            int sum=a+b;
            if(sum==k)
                return true;
            else if(sum>k)
                e--;
            else
                s++;
        }
        return false;
    }
};