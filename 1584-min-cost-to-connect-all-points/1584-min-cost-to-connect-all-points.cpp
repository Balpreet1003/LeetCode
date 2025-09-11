class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<int>key(n,INT_MAX), parent(n, -1);
        vector<bool>vis(n, false);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        pq.push({0,0});
        key[0]=0;
        while(!pq.empty()){
            while(!pq.empty() && vis[pq.top().second])
                pq.pop();
            if(pq.empty())
                break;
            auto [w, node]=pq.top(); pq.pop();
            vis[node]=true;

            for(int i=0;i<n;i++){
                if(!vis[i] && i!=node && key[i]>(abs(points[node][0]-points[i][0])+abs(points[node][1]-points[i][1]))){
                    key[i]=abs(points[node][0]-points[i][0])+abs(points[node][1]-points[i][1]);
                    parent[i]=node;
                    pq.push({abs(points[node][0]-points[i][0])+abs(points[node][1]-points[i][1]), i});
                }
            }
        }
        return accumulate(key.begin(), key.end(), 0);
    }
};