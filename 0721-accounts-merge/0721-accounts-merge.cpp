class Solution {
    int findParent(vector<int>& parent, int node){
        if(parent[node]==node)
            return node;
        return parent[node]=findParent(parent, parent[node]);
    }
    void unionSet(int u, int v, vector<int>& parent, vector<int>& rank){
        u=findParent(parent, u);
        v=findParent(parent, v);

        if(rank[u]<rank[v]){
            parent[u]=v;
        }
        else if(rank[v]<rank[u]){
            parent[v]=u;
        }
        else{
            parent[v]=u;
            rank[u]++;
        }
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        vector<int>parent(n, 0), rank(n, 0);
        for(int i=0;i<n;i++)
            parent[i]=i;
        
        unordered_map<string, int>trace;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                if(trace.count(accounts[i][j])){
                    unionSet(trace[accounts[i][j]], i, parent, rank);
                }
                else{
                    trace[accounts[i][j]]=i;
                }
            }
        }
        unordered_map<int,vector<string>>m;
        for(auto &[x, y]:trace){
            int par=findParent(parent, y);
            m[par].push_back(x);
        }
        vector<vector<string>>ans;
        for(auto [x,y]:m){
            vector<string>temp;
            temp.push_back(accounts[x][0]);
            sort(y.begin(), y.end());
            temp.insert(temp.end(), y.begin(), y.end());
            ans.push_back(temp);
        }
        return ans;
    }
};