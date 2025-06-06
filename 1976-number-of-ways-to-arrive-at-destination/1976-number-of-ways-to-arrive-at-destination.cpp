class Solution {
    const int MOD=1e9+7;
    int get_short_time(vector<vector<pair<int,int>>>&adj, int s,int& n){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dis(n,INT_MAX);
        pq.push({0,0});
        while(!pq.empty()){
            auto [t,node]=pq.top();
            pq.pop();

            for(auto &[x,t1]:adj[node]){
                if(t+t1<dis[x]){
                    dis[x]=t+t1;
                    pq.push({t+t1,x});
                }
            }
        }
        return dis[n-1];
    }
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto x:roads){
            adj[x[0]].push_back({x[1],x[2]});
            adj[x[1]].push_back({x[0],x[2]});
        }

        int short_time=get_short_time(adj,0,n);

        queue<pair<int,int>>q;
        q.push({0,0});
        int ans=0;

        while(!q.empty()){
            auto [node,t]=q.front();
            q.pop();

            if(node==n-1){
                ans=(ans+1)%MOD;
                continue;
            }
            if(t>short_time)continue;
            for(auto &[x,t1]:adj[node]){
                if(t + t1 <= short_time){
                    q.push({x, t + t1});
                }
            }
        }
        return ans;
    }
};