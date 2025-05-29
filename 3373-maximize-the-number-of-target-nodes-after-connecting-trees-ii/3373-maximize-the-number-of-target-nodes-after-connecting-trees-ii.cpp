class Solution {
    vector<int>height;
    pair<int,int>bfs(vector<vector<int>>&adj,int node){
        int odd=0,even=0;
        queue<pair<int,int>>q;
        q.push({node,0});
        vector<bool>visited(adj.size(),false);

        while(!q.empty()){
            int n=q.front().first;
            int h=q.front().second;
            q.pop();

            if(!visited[n]){
                if(h&1)odd++;
                else even++;
                visited[n]=true;
                for(auto i:adj[n]){
                    q.push({i,h+1});
                }
            }
        }
        return {odd,even};
    }
    void get_height(vector<vector<int>>&adj,int node){
        queue<pair<int,int>>q;
        q.push({node,0});
        vector<bool>visited(adj.size(),false);

        while(!q.empty()){
            int n=q.front().first;
            int h=q.front().second;
            q.pop();
            if(!visited[n]){
                height[n]=h;
                visited[n]=true;
                for(auto i:adj[n]){
                    q.push({i,h+1});
                }
            }
        }
    }
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n=edges1.size()+1;
        int m=edges2.size()+1;
        vector<vector<int>>adj1(n),adj2(m);
        for(auto x:edges1){
            adj1[x[0]].push_back(x[1]);
            adj1[x[1]].push_back(x[0]);
        }
        for(auto x:edges2){
            adj2[x[0]].push_back(x[1]);
            adj2[x[1]].push_back(x[0]);
        }

        auto node_cnt=bfs(adj2,0);
        int best=max(node_cnt.first,node_cnt.second);
        auto cnt_for_first=bfs(adj1,0);
        height.resize(n,0);
        get_height(adj1,0);
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            if(height[i]&1) {
                ans[i]=cnt_for_first.first + best;
            }
            else {
                ans[i]=cnt_for_first.second + best;
            }
        }
        return ans;
    }
};