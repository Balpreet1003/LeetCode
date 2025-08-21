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
    TreeNode* construct(vector<int>&nums, int l, int r){
        if(l>r)
            return NULL;
        if(l==r)
            return new TreeNode(nums[l]);
        TreeNode* node=new TreeNode(nums[l]);
        int i=l+1;
        for(;i<nums.size();i++){
            if(nums[l]<nums[i])
                break;
        }
        node->left=construct(nums, l+1, i-1);
        node->right=construct(nums, i, r);
        return node;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return construct(preorder, 0, preorder.size()-1);
    }
};