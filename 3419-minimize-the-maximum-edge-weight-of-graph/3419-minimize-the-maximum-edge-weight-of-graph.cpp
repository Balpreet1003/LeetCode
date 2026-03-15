class Solution {
    unordered_map<int, vector<pair<int, int>>>adj;
    bool is_poss(int n, int threshold, int mid){
        vector<int> vis(n, 0);
        queue<int>q;
        q.push(0);
        vis[0]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto& [x, w]:adj[node]){
                if(vis[x]==0 && w<=mid){
                    q.push(x);
                    vis[x]=1;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(vis[i]==0)
                return false;
        }
        return true;
    }

public:
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        int l=1, h=1;
        for(auto x:edges){
            adj[x[1]].push_back({x[0], x[2]});
            h=max(h, x[2]);
        }
        int ans=-1;
        while(l<=h){
            int mid=l-((l-h)/2);
            if(is_poss(n, threshold, mid)){
                ans=mid;
                h=mid-1;
            }
            else
                l=mid+1;
        }
        return ans;
    }
};