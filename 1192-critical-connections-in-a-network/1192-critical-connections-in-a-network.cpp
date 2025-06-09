class Solution {
    vector<int>tin,low;
    vector<bool>visited;
    vector<vector<int>>ans;
    int timer=0;

    void dfs(vector<vector<int>>&adj, int node,int par){
        visited[node]=true;
        tin[node]=low[node]=timer;
        timer++;

        for(auto x:adj[node]){
            if(x==par)continue;

            if(!visited[x]){
                dfs(adj,x,node);
                low[node]=min(low[node],low[x]);

                if(low[x]>tin[node]){
                    ans.push_back({node,x});
                }
            }
            else{
                low[node]=min(low[node],low[x]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        for(auto x:connections){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        tin=vector<int>(n);
        low=vector<int>(n);
        visited=vector<bool>(n,false);
        dfs(adj,0,-1);
        return ans;
    }
};