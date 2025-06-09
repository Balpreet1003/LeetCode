class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {

        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        if(connections.size()<n-1)return -1;
        vector<vector<int>>adj(n);
        for(int i=0;i<connections.size();i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }

        vector<bool> visited(n, false);
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                ans++;
                queue<int> q;
                q.push(i);
                visited[i] = true;

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
                    for (int neighbor : adj[node]) {
                        if (!visited[neighbor]) {
                            visited[neighbor] = true;
                            q.push(neighbor);
                        }
                    }
                }
            }
        }

        return ans - 1;
    }
};