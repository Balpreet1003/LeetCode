class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj_list(n);
        vector<int>indegree(n,0);
        vector<int>topo_sort;
        queue<int>q;

        for(auto x:prerequisites){
            adj_list[x[1]].push_back(x[0]);
        }

        for(int i=0;i<n;i++)
            for(auto x:adj_list[i])indegree[x]++;

        for(int i=0;i<n;i++)
            if(indegree[i]==0)q.push(i);

        while(!q.empty()){
            int node=q.front();
            q.pop();

            topo_sort.push_back(node);
            for(auto x:adj_list[node]){
                indegree[x]--;
                if(indegree[x]==0)q.push(x);
            }
        }
        return topo_sort.size()==n;
    }
};