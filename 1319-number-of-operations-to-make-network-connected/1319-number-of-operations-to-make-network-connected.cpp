class Solution {
    int findParent(vector<int>& parent, int node){
        if(parent[node]==node)
            return node;
        return parent[node]=findParent(parent, parent[node]);
    }
    void unionSet(int u, int v, vector<int>& parent, vector<int>& rank){
        u=findParent(parent, u);
        v=findParent(parent, v);
        if(rank[u]<rank[v])
            parent[u]=v;
        else if(rank[v]<rank[u])
            parent[v]=u;
        else{
            parent[v]=u;
            rank[u]++;
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int>parent(n, 0), rank(n, 0);
        int extraEdges=0, components=0;
        for(int i=0;i<n;i++)
            parent[i]=i;
        for(auto x:connections){
            int u=findParent(parent, x[0]);
            int v=findParent(parent, x[1]);
            if(u!=v){
                unionSet(u, v, parent, rank);
            }
            else{
                extraEdges++;
            }
        }
        for(int i=0;i<n;i++){
            if(parent[i]==i){
                components++;
            }
        }
        return extraEdges>=(components-1) ? components-1 : -1;
    }
};