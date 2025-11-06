class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj;
        for (auto c : connections) {
            int u = c[0], v = c[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<set<int>> powerGrid;
        unordered_set<int> visited;
        unordered_map<int, int> stationMap;

        for (int station = 1; station <= c; ++station) {
            if (visited.count(station)) continue;
            queue<int> q;
            visited.insert(station);
            q.push(station);
            set<int> gridSet;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                gridSet.insert(u);
                for (int v : adj[u]) {
                    if (visited.count(v) == 0) {
                        visited.insert(v);
                        q.push(v);
                    }
                }
            }
            for (int u : gridSet) {
                stationMap[u] = powerGrid.size();
            }
            powerGrid.push_back(gridSet);
        }

        vector<int> result;
        for (auto q : queries) {
            int type = q[0], station = q[1];
            int index = stationMap[station];
            if (type == 2) {
                powerGrid[index].erase(station);
            } else if (powerGrid[index].count(station) > 0) {
                result.push_back(station);
            } else if (powerGrid[index].size() > 0) {
                result.push_back(*powerGrid[index].begin());
            } else {
                result.push_back(-1);
            }
        }

        return result;
    }
};