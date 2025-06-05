class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj_list(n);
        for(auto x:flights){
            adj_list[x[0]].push_back({x[1],x[2]});
        }

        queue<pair<int,pair<int,int>>>pq;
        vector<int>dis(n,INT_MAX);

        pq.push({0,{src,0}});
        dis[src]=0;

        while(!pq.empty()){
            int cost=pq.front().first;
            int node=pq.front().second.first;
            int h=pq.front().second.second;
            pq.pop();

            if(h>k)continue;

            for(auto &[x,cst]:adj_list[node]){
                if(cst+cost<dis[x] && h<=k){
                    dis[x]=cst+cost;
                    pq.push({cst+cost,{x,h+1}});
                }
            }
        }
        return dis[dst]==INT_MAX ? -1 : dis[dst];
    }
};