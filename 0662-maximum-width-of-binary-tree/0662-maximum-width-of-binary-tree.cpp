class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        
        long long ans = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        
        while (!q.empty()) {
            int size = q.size();
            long long left = q.front().second;
            long long right = left;
            
            for (int i = 0; i < size; i++) {
                auto [node, idx] = q.front(); q.pop();
                idx -= left;
                right = idx;
                
                if (node->left) 
                    q.push({node->left, 2*idx});
                if (node->right) 
                    q.push({node->right, 2*idx+1});
            }
            
            ans = max(ans, right + 1);
        }
        
        return (int)ans;
    }
};