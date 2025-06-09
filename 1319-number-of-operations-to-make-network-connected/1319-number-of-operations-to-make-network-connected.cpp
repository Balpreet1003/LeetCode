class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1)return -1;
        vector<vector<int>>adj(n);
        for(int i=0;i<connections.size();i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        queue<int>pq;
        vector<bool>visited(n,false);

        pq.push(0);
        int cnt1=0;
        while(!pq.empty()){
            int node=pq.front();
            pq.pop();

            if(visited[node])continue;
            visited[node]=true;
            for(int x:adj[node]){
                if(!visited[x]){
                    pq.push(x);
                    cnt1++;
                }
            }
        }  
        int cnt2=0;
        for(int i=0;i<n;i++){
            if(!visited[i])cnt2++;
        }      
        int cnt3=connections.size()-cnt1;
        return cnt2<cnt3 ? -1 : cnt2;
    }
};