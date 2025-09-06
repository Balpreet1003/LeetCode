class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        unordered_map<int, vector<int>>adj;
        vector<int>indegree(n,0);
        for(int i=0;i<n;i++){
            indegree[i]=graph[i].size();
            for(int j:graph[i])
                adj[j].push_back(i);
        }
        queue<int>q;
        for(int i=0;i<n;i++)
            if(indegree[i]==0)
                q.push(i);

        vector<int>ans;
        while(!q.empty()){
            int node=q.front(); q.pop();
            ans.push_back(node);
            for(int x:adj[node]){
                if(--indegree[x]==0)
                    q.push(x);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};