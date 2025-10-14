class Solution {
    vector<int> ans;

    void dfs(unordered_map<int, vector<int>>& adj, unordered_map<int, int>& vis, int node) {
        vis[node] = 1;
        ans.push_back(node);
        for (auto x : adj[node]) {
            if (!vis.count(x)) {
                dfs(adj, vis, x);
            }
        }
    }

public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> adj;
        for (auto& x : adjacentPairs) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        int node = -1;
        for (auto& [i, x] : adj) {
            if (x.size() == 1) { 
                node = i;
                break;
            }
        }

        unordered_map<int, int> vis;
        dfs(adj, vis, node);
        return ans;
    }
};
