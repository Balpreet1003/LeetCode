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
    int get_num(string s){
        int ans=0, n=s.length();
        for(int i=0;i<n;i++){
            ans+=((s[i]-'0')*(1<<(n-i-1)));
        }
        return ans;
    }
    int solve(TreeNode* root, string s){
        if(!root)
            return 0;
        if(!root->left && !root->right){
            s+=to_string(root->val);
            cout<<s<<endl;
            return get_num(s);
        }
        return solve(root->left, s+to_string(root->val))+solve(root->right, s+to_string(root->val));
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        return solve(root,"");
    }
};