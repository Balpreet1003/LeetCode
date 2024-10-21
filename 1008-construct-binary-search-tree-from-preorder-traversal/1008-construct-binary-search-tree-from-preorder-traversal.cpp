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
    TreeNode*constructBst(vector<int>&nums,int l,int u,int& i){
        if(i==nums.size() || nums[i]<l || nums[i]>u)return NULL;
        TreeNode*node=new TreeNode(nums[i++]);
        node->left=constructBst(nums,l,nums[i-1],i);
        node->right=constructBst(nums,nums[i-1],u,i);
        return node;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return constructBst(preorder,0,1001,i);
    }
};