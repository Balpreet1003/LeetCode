#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        vector<char> vis(n, 0);
        int answer = 0;

        for (int s = 0; s < n; ++s) {
            if (vis[s]) continue;

            // BFS this component
            queue<int> q;
            q.push(s);
            vis[s] = 1;

            long long nodes = 0;
            long long degreeSum = 0;  // sum of degrees within this component

            while (!q.empty()) {
                int u = q.front(); q.pop();
                nodes++;
                degreeSum += (long long)g[u].size();  // add degree of u

                for (int v : g[u]) {
                    if (!vis[v]) {
                        vis[v] = 1;
                        q.push(v);
                    }
                }
            }

            // For a clique on 'nodes' vertices: sum of degrees = nodes*(nodes-1)
            if (degreeSum == nodes * (nodes - 1)) {
                answer++;
            }
        }

        return answer;
    }
};
