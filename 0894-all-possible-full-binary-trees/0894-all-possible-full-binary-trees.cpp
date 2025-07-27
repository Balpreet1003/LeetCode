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
    unordered_map<int,vector<TreeNode*>>dp;
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n % 2 == 0){
            return {};
        }
        if(dp.find(n)!=dp.end()){
            return dp[n];
        }
        vector<TreeNode*>ans;
        if(n==1){
            ans.push_back(new TreeNode(0));
        }
        else {
            for(int i=1;i<n;i+=2){
                vector<TreeNode*>left_tree=allPossibleFBT(i);
                vector<TreeNode*>right_tree=allPossibleFBT(n-i-1);

                for(auto left_child:left_tree){
                    for(auto right_child:right_tree){
                        ans.push_back(new TreeNode(0, left_child, right_child));
                    }
                }
            }
        }
        return dp[n]=ans;
    }
};