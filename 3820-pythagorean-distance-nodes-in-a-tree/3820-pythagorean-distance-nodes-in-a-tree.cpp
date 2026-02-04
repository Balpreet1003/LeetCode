#define vi vector
#define pb push_back

class Solution {
    vi<vi<int>>adj, arr;
    vi<int> bfs(int x, int n){
        vi<int>ans(n, 0);
        queue<pair<int, int>>q;
        vi<int>vis(n, 0);
        q.push({x, 0});
        vis[x]=1;
        while(!q.empty()){
            auto [node, h]=q.front();
            q.pop();

            ans[node]=h;
            for(int i:adj[node]){
                if(!vis[i]){
                    q.push({i, h+1});
                    vis[i]=1;
                }
            }
        }
        return ans;
    }

    bool poss(vi<int>arr1){
        sort(arr1.begin(), arr1.end());
        return arr1[0]*1LL+arr1[1]*1LL==arr1[2]*1LL;
    }
public:
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        adj.resize(n);
        for(auto x:edges){
            adj[x[0]].pb(x[1]);
            adj[x[1]].pb(x[0]);
        }

        arr.resize(3);
        arr[0]=bfs(x, n);
        arr[1]=bfs(y, n);
        arr[2]=bfs(z, n);

        int ans=0;
        for(int i=0;i<n;i++){
            if(poss({arr[0][i]*arr[0][i], arr[1][i]*arr[1][i], arr[2][i]*arr[2][i]})) {
                ans++;
            }
        }
        return ans;
    }
};