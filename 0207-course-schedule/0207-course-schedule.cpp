class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj_list;
        for(auto x:prerequisites)
            adj_list[x[0]].push_back(x[1]);
        
        vector<int>in_degree(numCourses, 0);
        for(int i=0;i<numCourses;i++)
            for(int j:adj_list[i])
                in_degree[j]++;

        queue<int>q;
        vector<int>ans;
        for(int i=0;i<numCourses;i++)
            if(in_degree[i]==0)
                q.push(i);

        while(!q.empty()){
            int node=q.front(); q.pop();
            ans.push_back(node);
            for(int x:adj_list[node]){
                in_degree[x]--;
                if(in_degree[x]==0)
                    q.push(x);
            }
        }
        return ans.size()==numCourses;
    }
};