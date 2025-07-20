class Solution {
    // Return:
    // 0 -> not covered
    // 1 -> covered (no camera)
    // 2 -> has camera
    int dfs(TreeNode* node, int& cameras) {
        if (!node) return 1;

        int left = dfs(node->left, cameras);
        int right = dfs(node->right, cameras);

        if (left == 0 || right == 0) {
            cameras++;
            return 2;
        }

        if (left == 2 || right == 2) {
            return 1;
        }

        return 0;
    }
public:
    int minCameraCover(TreeNode* root) {
        int cameras = 0;
        if (dfs(root, cameras) == 0) {
            cameras++;
        }
        return cameras;
    }

};