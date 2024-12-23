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
    int getCount(vector<int>& arr) {
        int ans = 0;
        vector<pair<int, int>> indexedArr;
        for (int i = 0; i < arr.size(); i++) {
            indexedArr.push_back({arr[i], i});
        }

        sort(indexedArr.begin(), indexedArr.end());

        vector<bool> visited(arr.size(), false);

        for (int i = 0; i < arr.size(); i++) {
            if (visited[i] || indexedArr[i].second == i) {
                continue;
            }

            int cycleSize = 0;
            int j = i;
            while (!visited[j]) {
                visited[j] = true;
                j = indexedArr[j].second;
                cycleSize++;
            }

            if (cycleSize > 1) {
                ans += (cycleSize - 1);
            }
        }

        return ans;
    }

public:
    int minimumOperations(TreeNode* root) {
        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();
            vector<int> arr;

            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }

                arr.push_back(node->val);
            }

            ans += getCount(arr);
        }

        return ans;
    }
};