class Solution {
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ans=0,n=grid.size(),m=grid[0].size();
        vector<vector<int>>time(n,vector<int>(m,-1));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    time[i][j]=0;
                }
            }
        }
        
        while(!q.empty()){
            auto [i,j]=q.front();
            q.pop();

            for(int k=0;k<4;k++){
                int i1=i+dx[k],j1=j+dy[k];
                if(i1>=0 && i1<n && j1>=0 && j1<m && grid[i1][j1]==1){
                    grid[i1][j1]=2;
                    q.push({i1,j1});
                    time[i1][j1]=time[i][j]+1;
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)return -1;
                ans=max(ans,time[i][j]);
            }
        }
        return ans;
    }
};