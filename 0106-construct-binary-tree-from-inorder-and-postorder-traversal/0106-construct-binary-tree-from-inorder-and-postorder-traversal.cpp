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
    TreeNode*solve(vector<int>&a,vector<int>&b,int i,int j,int&k){
        if(i>j || k<0)return NULL;

        TreeNode*node=new TreeNode(a[k]);
        int l=i;
        for(;l<=j;l++){
            if(b[l]==a[k])break;
        }
        k--;
        node->right=solve(a,b,l+1,j,k);
        node->left=solve(a,b,i,l-1,k);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& b, vector<int>& a) {
        int k=a.size()-1;
        return solve(a,b,0,a.size()-1,k);
    }
};