class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<vector<int>>>adj;
        for(auto x:edges){
            adj[x[0]].push_back({x[1],x[2],x[3]});
        }
        vector<long long> mini(n,-1);
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>>pq;
        pq.push({0,0});
        mini[0]=0;
        while(!pq.empty()){
            auto [t,node]=pq.top();
            pq.pop();
            if(mini[node]!=-1 && t>mini[node]){
                continue;
            }
            if(node==n-1){
                return t;
            }
            for(auto y:adj[node]){
                int x=y[0];
                int s=y[1];
                int e=y[2];
                long long t1=max(t,1LL*s);
                if(t1<=e){
                    if(mini[x]==-1 || (t1+1)<mini[x]){
                        mini[x]=t1+1;
                        pq.push({t1+1,x});
                    }
                }
            }
        }
        return -1;
    }
};