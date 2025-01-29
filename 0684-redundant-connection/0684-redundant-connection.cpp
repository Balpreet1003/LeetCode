class Solution {
public:
    class DSU {
    public:
        vector<int> parent, rank;
        
        DSU(int n) {
            parent.resize(n + 1);
            rank.resize(n + 1, 1);
            for (int i = 0; i <= n; i++) parent[i] = i;
        }
        
        int find(int x) {
            if (parent[x] != x)
                parent[x] = find(parent[x]);
            return parent[x];
        }
        
        bool unite(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            if (rootX == rootY) return false;
            
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
            return true;
        }
    };

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n);
        
        for (auto& edge : edges) {
            if (!dsu.unite(edge[0], edge[1])) {
                return edge; 
            }
        }
        return {-1, -1};
    }
};