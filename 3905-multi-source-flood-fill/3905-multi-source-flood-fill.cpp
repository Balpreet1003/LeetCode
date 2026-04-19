class Solution {
    int const dx[4]={0, 1, 0, -1};
    int const dy[4]={1, 0, -1, 0};
    bool is_poss(int n, int m, int i, int j)
    {
        return i>=0 && i<n && j>=0 && j<m;
    }
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>>ans(n, vector<int>(m, 0));
        queue<pair<int, int>>q;
        vector<vector<int>>vis(n, vector<int>(m, 0)), level(n, vector<int>(m, 0));
        for(auto x:sources)
        {
            ans[x[0]][x[1]]=max(ans[x[0]][x[1]], x[2]);
            q.push({x[0], x[1]});
            vis[x[0]][x[1]]=1;
        }
        while(!q.empty())
        {
            auto [x, y]=q.front();
            q.pop();
            for(int i=0;i<4;i++)
            {
                int x1=x+dx[i], y1=y+dy[i];
                if(is_poss(n, m, x1, y1))
                {
                    if(!vis[x1][y1])
                    {
                        vis[x1][y1]=1;
                        level[x1][y1]=level[x][y]+1;
                        ans[x1][y1]=ans[x][y];
                        q.push({x1, y1});
                    }
                    else if(level[x1][y1]==level[x][y]+1)
                        ans[x1][y1]=max(ans[x1][y1], ans[x][y]);
                }
            }
        }
        return ans;
    }
};