class Solution {
    vector<vector<vector<TreeNode*>>>dp;
    vector<TreeNode*> solve(int l, int r){
        vector<TreeNode*> ans;
        if (l > r) {
            ans.push_back(nullptr);
            return ans;
        }

        for (int i = l; i <= r; i++) {
            vector<TreeNode*> left_arr = solve(l, i - 1);
            vector<TreeNode*> right_arr = solve(i + 1, r);

            if(!dp[l][r].empty()){
                return dp[l][r];
            }
            for (auto left : left_arr) {
                for (auto right : right_arr) {
                    TreeNode* node = new TreeNode(i);
                    node->left = left;
                    node->right = right;
                    ans.push_back(node);
                }
            }
        }
        return dp[l][r] = ans;
    }

public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        dp.resize(n+1,vector<vector<TreeNode*>>(n+1));
        return solve(1, n);
    }
};