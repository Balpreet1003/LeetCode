class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>>ans(n,vector<int>(m,0));
        vector<vector<int>>visited(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    ans[i][j]=0;
                    visited[i][j]=1;
                }
                else{
                    visited[i][j]=0;
                }
            }
        }
        vector<int>dx={-1,0,1,0};
        vector<int>dy={0,1,0,-1};
        while(!q.empty()){
            auto fNode=q.front();
            int x=fNode.first.first;
            int y=fNode.first.second;
            q.pop();
            int dis=fNode.second;
            ans[x][y]=dis;
            for(int i=0;i<4;i++){
                int x1=x+dx[i];
                int y1=y+dy[i];

                if(x1>=0 && x1<n && y1>=0 && y1<m && visited[x1][y1]==0){
                    visited[x1][y1]=1;
                    q.push({{x1,y1},dis+1});
                }
            }
        }
        return ans;
    }
};