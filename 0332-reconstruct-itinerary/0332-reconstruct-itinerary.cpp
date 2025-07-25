class Solution {
    vector<string> ans;

    void dfs(string node, unordered_map<string, multiset<string>>& adj) {
        while (!adj[node].empty()) {
            auto next = *adj[node].begin();
            adj[node].erase(adj[node].begin());
            dfs(next, adj);
        }
        ans.push_back(node);
    }

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> adj;

        for (auto& ticket : tickets) {
            adj[ticket[0]].insert(ticket[1]);
        }

        dfs("JFK", adj);

        reverse(ans.begin(), ans.end());

        return ans;
    }
};