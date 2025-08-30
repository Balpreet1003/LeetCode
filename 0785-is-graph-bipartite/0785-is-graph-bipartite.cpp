class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        unordered_map<int,int>m;
        vector<bool>vis(graph.size(),false);
        queue<pair<int,bool>>q;
        q.push({0,true});
        m[0]=true;
        vis[0]=true;
        while(!q.empty()){
            auto [node, colour]=q.front();
            q.pop();

            for(auto x:graph[node]){
                if(!vis[x]){
                    q.push({x,!colour});
                    vis[x]=true;
                    m[x]=(!colour);
                }
                else if(m[x]==colour)
                    return false;
            }
        }
        return true;
    }
};