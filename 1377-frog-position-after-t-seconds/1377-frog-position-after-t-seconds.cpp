class Solution {
    double solve(unordered_map<int,vector<int>>& adj, vector<bool>& vis, int target, int t, int curr) {
        if (t == 0 || adj[curr].empty()) {
            return curr == target ? 1.0 : 0.0;
        }

        vis[curr] = true;

        int childCount = 0;
        for (int nei : adj[curr]) {
            if (!vis[nei]) childCount++;
        }

        if (childCount == 0) {
            return curr == target ? 1.0 : 0.0;
        }

        double prob = 0.0;
        for (int nei : adj[curr]) {
            if (!vis[nei]) {
                prob += solve(adj, vis, target, t - 1, nei);
            }
        }

        return prob / childCount;
    }

public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        unordered_map<int, vector<int>> adj;
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> vis(n + 1, false);
        return solve(adj, vis, target, t, 1);
    }
};