class Solution {
    int t=1;
    vector<vector<int>>ans;
    void dfs(unordered_map<int,vector<int>>& adj, vector<bool>& vis, vector<int>& tin, vector<int>& low, int i, int par){
        vis[i]=true;
        tin[i]=low[i]=t;
        t++;
        for(auto x:adj[i]){
            if(x==par)continue;
            if(!vis[x]){
                dfs(adj, vis, tin, low, x, i);
                low[i]=min(low[i], low[x]);
                if(low[x]>tin[i]){
                    ans.push_back({i, x});
                }
            }
            else{
                low[i]=min(low[i], low[x]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        unordered_map<int, vector<int>>adj;
        for(auto x:connections){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        vector<bool>vis(n, false);
        vector<int>tin(n), low(n);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(adj, vis, tin, low, i, -1);
            }
        }
        return ans;
    }
};