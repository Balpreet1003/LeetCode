/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    vector<TreeNode*>path;
    unordered_map<TreeNode*,bool>m;
    vector<int>ans;
    void findPath(TreeNode*root,TreeNode*t,vector<TreeNode*>&a){
        if(!root)return;
        if(root==t){
            a.push_back(root);
            path=a;
            a.pop_back();
            return;
        }
        a.push_back(root);
        findPath(root->left,t,a);
        findPath(root->right,t,a);
        a.pop_back();
    }
    void getNode(TreeNode*root,int k){
        if(!root || k<0)return;
        if(k==0){
            ans.push_back(root->val);
            return;
        }
        if(m.find(root->left)==m.end())getNode(root->left,k-1);
        if(m.find(root->right)==m.end())getNode(root->right,k-1);
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* t, int k) {
        vector<TreeNode*>a;
        findPath(root,t,a);
        for(auto i:path)m[i]=1;
        int n=path.size();
        for(int i=0;i<n;i++){
            int d=k-(n-i-1);
            getNode(path[i],d);
        }
        return ans;
    }
};