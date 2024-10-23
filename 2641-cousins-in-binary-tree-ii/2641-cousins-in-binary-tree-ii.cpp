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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*>q;
        unordered_map<TreeNode*,int>m;
        q.push(root);
        int sum1=root->val;
        int sum2=0;
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode*node=q.front();
                q.pop();
                int x=node->val;
                if(m.find(node)!=m.end())x+=m[node];
                node->val=sum1-x;
                if(node->left){
                    q.push(node->left);
                    sum2+=node->left->val;
                    if(node->right) m[node->left]=node->right->val;
                }
                if(node->right){
                    q.push(node->right);
                    sum2+=node->right->val;
                    if(node->left) m[node->right]=node->left->val;
                }
            }
            sum1=sum2;
            sum2=0;
        }
        return root;
    }
};