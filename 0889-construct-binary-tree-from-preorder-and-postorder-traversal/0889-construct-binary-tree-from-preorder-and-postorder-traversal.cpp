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
    TreeNode* constructTree(vector<int>&preOrder,unordered_map<int,int>&mp,int & i,int prev){
        //bc
        if(i==preOrder.size() || mp[prev]<mp[preOrder[i]] ){
            return NULL;
        }
        //1 case
        //creation of node
        TreeNode* root=new TreeNode(preOrder[i++]);
        root->left=constructTree(preOrder,mp,i,root->val);
        root->right=constructTree(preOrder,mp,i,root->val);
        return root;
    }
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        unordered_map<int,int>postMap;
        for(int i=0;i<postorder.size();i++){
            postMap[postorder[i]]=i;
        }
        int i=0;
        return constructTree(preorder,postMap,i,preorder[0]);
    }
};