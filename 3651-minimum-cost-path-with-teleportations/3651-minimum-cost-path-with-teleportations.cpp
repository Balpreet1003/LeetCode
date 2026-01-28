#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& grid, int K) {
        int m = grid.size();
        int n = grid[0].size();
        const long long INF = 1e18;

        // dist[i][j][k] = minimum cost to reach (i,j) using k teleports
        vector<vector<vector<long long>>> dist(m,
            vector<vector<long long>>(n, vector<long long>(K+1, INF)));

        // Preprocess cells sorted by value (for teleport optimization)
        vector<tuple<int,int,int>> cells; // (value, i, j)
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cells.emplace_back(grid[i][j], i, j);
            }
        }
        sort(cells.begin(), cells.end()); // increasing value

        // Dijkstra state: (cost, i, j, kUsed)
        priority_queue<tuple<long long,int,int,int>,
                       vector<tuple<long long,int,int,int>>,
                       greater<tuple<long long,int,int,int>>> pq;

        dist[0][0][0] = 0;
        pq.push({0, 0, 0, 0});

        // For teleport optimization: for each kUsed and value index
        vector<vector<int>> ptr(K+1, vector<int>(cells.size(), 0));

        while(!pq.empty()){
            auto [cost, i, j, k] = pq.top(); pq.pop();
            if(cost > dist[i][j][k]) continue;

            // Reached destination
            if(i == m-1 && j == n-1) return cost;

            // Normal moves
            if(i+1 < m){
                long long nc = cost + grid[i+1][j];
                if(nc < dist[i+1][j][k]){
                    dist[i+1][j][k] = nc;
                    pq.push({nc, i+1, j, k});
                }
            }
            if(j+1 < n){
                long long nc = cost + grid[i][j+1];
                if(nc < dist[i][j+1][k]){
                    dist[i][j+1][k] = nc;
                    pq.push({nc, i, j+1, k});
                }
            }

            // Teleport
            if(k < K){
                int curVal = grid[i][j];
                // teleport to all cells with value <= curVal
                int &p = ptr[k][0]; // shared pointer idea
                while(p < (int)cells.size() && get<0>(cells[p]) <= curVal){
                    auto [v, x, y] = cells[p];
                    if(dist[x][y][k+1] > cost){
                        dist[x][y][k+1] = cost;
                        pq.push({cost, x, y, k+1});
                    }
                    p++;
                }
            }
        }

        long long ans = INF;
        for(int k=0;k<=K;k++) ans = min(ans, dist[m-1][n-1][k]);
        return (ans==INF ? -1 : (int)ans);
    }
};
