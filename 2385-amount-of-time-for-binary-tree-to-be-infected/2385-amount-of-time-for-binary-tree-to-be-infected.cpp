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
    TreeNode* s;
    unordered_map<TreeNode*, TreeNode*>parent;
    void get_parent(TreeNode* root, int start){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            if(node->val == start)
                s = node;
            if(node->left){
                q.push(node->left);
                parent[node->left] = node;
            }
            if(node->right){
                q.push(node->right);
                parent[node->right] = node;
            }
        }
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        get_parent(root, start);

        unordered_map<TreeNode*, int> vis;
        int ans=0;
        queue<pair<TreeNode*, int>>q;
        q.push({s, 0});
        while(!q.empty()){
            auto [node, t]=q.front();
            q.pop();
            vis[node]=1;
            ans=max(ans, t);
            if(node->left && !vis.count(node->left))
                q.push({node->left, t+1});
            if(node->right && !vis.count(node->right))
                q.push({node->right, t+1});
            if(parent.count(node) && !vis[parent[node]])
                q.push({parent[node],t+1});
        }
        return ans;
    }
};