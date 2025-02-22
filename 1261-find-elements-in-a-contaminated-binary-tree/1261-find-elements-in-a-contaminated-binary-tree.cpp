class FindElements {
public:
    void solve(TreeNode* root) {
        if (root == NULL) {
            return;  // Base case: If the node is NULL, stop the recursion
        }

        // Store the restored value in the list
        values_list.push_back(root->val);

        // Process left child (if exists)
        if (root->left != NULL) {
            root->left->val = root->val * 2 + 1;  // Assign new value
        }
        solve(root->left);

        // Process right child (if exists)
        if (root->right != NULL) {
            root->right->val = root->val * 2 + 2;  // Assign new value
        }
        solve(root->right);
    }

    vector<int> values_list;  // Stores recovered values of the tree

    /**
     * Constructor initializes the recovery process of the tree.
     * - The root node is set to `0`.
     * - Calls `solve()` to restore the entire tree.
     */
    FindElements(TreeNode* root) {
        root->val = 0;  // Initialize root value to 0
        solve(root);
    }
    bool find(int target) {
        for (int i = 0; i < values_list.size(); i++) {
            if (target == values_list[i]) return true;
        }
        return false; 
    }
};