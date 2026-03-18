class Solution {
    unordered_map<string, vector<string>>adj;
    unordered_map<string, int>vis;
    void dfs(string u){
        vis[u]=1;
        for(auto v:adj[u]){
            if(!vis.count(v)){
                dfs(v);
            }
        }
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        for(int i=0;i<n;i++){
            string s1=to_string(stones[i][0])+"/"+to_string(stones[i][1]);
            adj[s1]={};
            for(int j=0;j<n;j++){
                if(i!=j && (stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1])){
                    string s2=to_string(stones[j][0])+"/"+to_string(stones[j][1]);
                    adj[s1].push_back(s2);
                    adj[s2].push_back(s1);
                }
            }
        }
        int ans=0;
        for(auto [x, y]:adj){
            if(!vis.count(x)){
                dfs(x);
                ans++;
            }
        }
        return n-ans;
    }
};