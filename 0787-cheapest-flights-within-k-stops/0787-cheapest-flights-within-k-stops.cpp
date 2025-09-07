class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int,int>>>adj_list;
        for(auto x:flights){
            adj_list[x[0]].push_back({x[1],x[2]});
        }

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>q;
        vector<vector<int>>ans(n, vector<int>(k+2,INT_MAX));
        q.push({0, 0, src});
        ans[src][0]=0;
        while(!q.empty()){
            int node=q.top()[2], h=q.top()[1], wt=q.top()[0];
            q.pop();

            if(node==dst)
                return wt;
            if(h>k)
                continue;
            
            for(auto &[x,w]:adj_list[node]){
                if(ans[x][h+1]>wt+w){
                    ans[x][h+1]=wt+w;
                    q.push({wt+w, h+1, x});
                }
            }
        }
        return -1;
    }
};