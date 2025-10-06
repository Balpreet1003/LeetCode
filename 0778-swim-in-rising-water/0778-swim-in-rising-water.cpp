class Solution {
public:
    struct DSU {
        vector<int> parent, rank;
        DSU(int n) {
            parent.resize(n,0);
            rank.resize(n,0);
            iota(parent.begin(), parent.end(), 0);
        }
        int find(int x) {
            if (x != parent[x]) parent[x] = find(parent[x]);
            return parent[x];
        }
        void unite(int x, int y) {
            x = find(x), y = find(y);
            if (x == y) return;
            if (rank[x] < rank[y]) swap(x,y);
            parent[y] = x;
            if (rank[x] == rank[y]) rank[x]++;
        }
    };

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<array<int,3>> cells;
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                cells.push_back({grid[i][j], i, j});
            }
        }
        sort(cells.begin(), cells.end());
        DSU dsu(n*n);
        vector<vector<int>> active(n, vector<int>(n,0));
        vector<int> dir = {0,1,0,-1,0};

        for (auto &cell : cells) {
            int h = cell[0], r = cell[1], c = cell[2];
            active[r][c] = 1;
            for (int k=0;k<4;k++) {
                int nr = r + dir[k], nc = c + dir[k+1];
                if (nr>=0 && nc>=0 && nr<n && nc<n && active[nr][nc]) {
                    dsu.unite(r*n+c, nr*n+nc);
                }
            }
            if (dsu.find(0) == dsu.find(n*n-1)) return h;
        }
        return -1;
    }
};