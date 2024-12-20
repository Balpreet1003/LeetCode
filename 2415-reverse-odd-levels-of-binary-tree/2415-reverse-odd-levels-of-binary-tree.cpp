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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*>q1;
        q1.push(root);
        int level=0;
        while(!q1.empty()){
            vector<TreeNode*>arr;
            int n=q1.size();
            for(int i=0;i<n;i++){
                TreeNode* temp=q1.front();
                q1.pop();
                if(temp->left){
                    q1.push(temp->left);
                }
                if(temp->right){
                    q1.push(temp->right);
                }
                if(level&1){
                    arr.push_back(temp);
                }
            }
            if(level&1){
                int i=0,j=arr.size()-1;
                while(i<j){
                    swap(arr[i++]->val,arr[j--]->val);
                }
            }
            level++;
        }
        return root;
    }
};