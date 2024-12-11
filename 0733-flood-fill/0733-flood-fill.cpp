class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& img, int sr, int sc, int color) {
        int n=img.size(),m=img[0].size();
        vector<vector<int>>ans=img;
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        queue<pair<int,int>>q;
        q.push({sr,sc});
        ans[sr][sc]=color;

        vector<int>dx={-1,0,1,0};
        vector<int>dy={0,1,0,-1};

        while(!q.empty()){
            auto fNode=q.front();
            q.pop();
            
            for(int i=0;i<4;i++){
                int x1=fNode.first+dx[i];
                int y1=fNode.second+dy[i];

                if(x1>=0 && x1<n && y1>=0 && y1<m && ans[x1][y1]==img[sr][sc] && !visited[x1][y1]){
                    ans[x1][y1]=color;
                    q.push({x1,y1});
                    visited[x1][y1]=true;
                }
            }
        }
        return ans;
    }
};