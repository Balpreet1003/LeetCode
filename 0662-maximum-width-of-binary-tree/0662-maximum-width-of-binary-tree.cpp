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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        // Queue will store pairs of TreeNode and its index
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        int ans = 0;

        while (!q.empty()) {
            int size = q.size();
             long long minIndex = q.front().second; 
            int first = 0, last = 0;

            for (int i = 0; i < size; i++) {
                auto [node, index] = q.front();
                q.pop();
                
                 long long currIndex = index - minIndex;

                if (i == 0) first = currIndex;  
                if (i == size - 1) last = currIndex; 

                if (node->left) q.push({node->left, 2 * currIndex + 1});
                if (node->right) q.push({node->right, 2 * currIndex + 2});
            }
            ans = max(ans, last - first + 1);
        }

        return ans;
    }
};