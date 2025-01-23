class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int ans=0,n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            int cnt=0;
            int prev=-1;
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 || grid[i][j]==-1){
                    cnt++;
                }
                if(cnt>1 && (grid[i][j]==1 || grid[i][j]==-1)){
                    grid[i][j]=-1;
                    grid[i][prev]=-1;
                }
                if(grid[i][j]==1 || grid[i][j]==-1){
                    prev=j;
                }
            }
        }
        for(int j=0;j<m;j++){
            int cnt=0;
            int prev=-1;
            for(int i=0;i<n;i++){
                if(grid[i][j]==1 || grid[i][j]==-1){
                    cnt++;
                }
                if(cnt>1 && (grid[i][j]==1 || grid[i][j]==-1)){
                    grid[i][j]=-1;
                    grid[prev][j]=-1;
                }
                if(grid[i][j]==1 || grid[i][j]==-1){
                    prev=i;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==-1)ans++;
            }
        }
        return ans;
    }
};