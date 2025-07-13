class DSU {
    vector<int> parent, rank;
public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
        return true;
    }
};

class Solution {
    static bool cmd(vector<int>&a,vector<int>&b){
        return a[2]<b[2];
    }
public:
    int minCost(int n, vector<vector<int>>& edges, int k) {
        if(k>=n){
            return 0;
        }
        sort(edges.begin(),edges.end(),cmd);
        DSU dsu(n);
        vector<int>wt;
        for(auto x:edges){
            if(dsu.unite(x[0],x[1])){
                wt.push_back(x[2]);
                if(wt.size()==n-1){
                    break;
                }
            }
        }
        return wt[n-k-1];
    }
};