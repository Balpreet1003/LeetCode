class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto x:times){
            adj[x[0]-1].push_back({x[1]-1,x[2]});
        }

        vector<int>ans(n,INT_MAX);
        ans[k-1]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k-1});
        while(!pq.empty()){
            auto [w,node]=pq.top();
            pq.pop();

            if(w > ans[node]) continue;

            for(auto &[x,w1]:adj[node]){
                if(w+w1<ans[x]){
                    ans[x]=w+w1;
                    pq.push({ans[x],x});
                }
            }
        }
        int res=0;
        for(auto x:ans){
            if(x==INT_MAX)return -1;
            res=max(res,x);
        }
        return res;
    }
};