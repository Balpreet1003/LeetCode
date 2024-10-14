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
    map<pair<int,int>,vector<int>>m;int mini=INT_MAX,maxi=INT_MIN,height=0;
    void verticalOrderTraversal(TreeNode*root,int i,int j){
        //bc
        if(root==NULL)return;
        //1 case
        mini=min(mini,i);
        maxi=max(maxi,i);
        m[{i,j}].push_back(root->val);
        verticalOrderTraversal(root->left,i-1,j+1);
        verticalOrderTraversal(root->right,i+1,j+1);
        height=max(height,j);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        verticalOrderTraversal(root,0,0);
        vector<vector<int>>ans(maxi-mini+1);
        int k=0;
        for(int i=mini;i<=maxi;i++){
            for(int j=0;j<=height;j++){
                vector<int>temp=m[{i,j}];
                sort(temp.begin(),temp.end());
                for(int l=0;l<temp.size();l++){
                    ans[k].push_back(temp[l]);
                }
            }
            k++;
        }
        return ans;
    }
};