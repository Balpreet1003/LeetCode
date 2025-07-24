class Solution {
    unordered_map<int, vector<int>> adj;
    unordered_map<int, unordered_set<int>> desc;
    vector<int> xor_arr;
    vector<bool> vis;

    void dfs(vector<int>& nums, int node) {
        vis[node] = true;
        xor_arr[node] = nums[node];
        desc[node].insert(node); // Add self to descendant set

        for (auto child : adj[node]) {
            if (!vis[child]) {
                dfs(nums, child);
                xor_arr[node] ^= xor_arr[child];
                desc[node].insert(desc[child].begin(), desc[child].end());
            }
        }
    }

public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();

        // Build adjacency list
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        xor_arr.resize(n);
        vis.resize(n, false);

        dfs(nums, 0);  // Perform DFS starting from root node 0

        int total_xor = xor_arr[0];
        int ans = INT_MAX;

        // Try all pairs of nodes where edges could be removed
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int xor_i = xor_arr[i];
                int xor_j = xor_arr[j];
                int x, y, z;

                if (desc[i].count(j)) {
                    // j is in subtree of i
                    x = xor_j;
                    y = xor_i ^ xor_j;
                    z = total_xor ^ xor_i;
                }
                else if (desc[j].count(i)) {
                    // i is in subtree of j
                    x = xor_i;
                    y = xor_j ^ xor_i;
                    z = total_xor ^ xor_j;
                }
                else {
                    // i and j are in different subtrees
                    x = xor_i;
                    y = xor_j;
                    z = total_xor ^ xor_i ^ xor_j;
                }

                int score = max({x, y, z}) - min({x, y, z});
                ans = min(ans, score);
            }
        }

        return ans;
    }
};