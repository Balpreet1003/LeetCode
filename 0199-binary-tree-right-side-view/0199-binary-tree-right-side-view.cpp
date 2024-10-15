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
    vector<int> rightSideView(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        if (!root) return {};
        unordered_map<int,int>m;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        int mini=0,maxi=0;
        while(!q.empty()){
            auto i=q.front();
            q.pop();
            if(m.find(i.second)==m.end())m[i.second]=i.first->val;
            mini=min(mini,i.second);
            maxi=max(maxi,i.second);
            if(i.first->right)q.push({i.first->right,i.second+1});
            if(i.first->left)q.push({i.first->left,i.second+1});
        }
        vector<int>ans;
        for(int i=mini;i<=maxi;i++){
            ans.push_back(m[i]);
        }
        return ans;
    }
};