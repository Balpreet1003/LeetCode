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
    unordered_map<int, pair<int, int>>mp;
    void solve(TreeNode* root){
        queue<pair<TreeNode*, pair<int, int>>>q;
        q.push({root, {0, 0}});
        while(!q.empty()){
            auto& [node, x]=q.front();
            auto& [l, h]=x;
            q.pop();
            if(mp.count(h)){
                mp[h].first=min(mp[h].first, l);
                mp[h].second=max(mp[h].second, l);
            }
            else{
                mp[h]={l, l};
            }

            if(node->left)
                q.push({node->left, {2*l, h+1}});
            if(node->right)
                q.push({node->right, {2*l+1, h+1}});
        }
    }
public:
    int widthOfBinaryTree(TreeNode* root) {
        solve(root);
        int ans=0;
        for(auto& [x, y]:mp){
            cout<<y.second<<" - "<<y.first<<endl;
            ans=max(ans, y.second-y.first+1);
        }
        return ans;
    }
};