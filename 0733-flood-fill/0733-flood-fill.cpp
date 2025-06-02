class Solution {
    vector<int>dx={-1,0,1,0};
    vector<int>dy={0,1,0,-1};
    void dfs(vector<vector<int>>&nums,vector<vector<bool>>&visited,int i,int j,int&color,int initial_color) {
        if(i<0 || i>=nums.size() || j<0 || j>=nums[0].size() || visited[i][j] || nums[i][j]!=initial_color)return;

        nums[i][j]=color;
        visited[i][j]=true;

        for(int k=0;k<4;k++){
            dfs(nums,visited,i+dx[k],j+dy[k],color,initial_color);
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& img, int sr, int sc, int color) {
        int n=img.size(),m=img[0].size();
        vector<vector<int>>ans=img;
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        dfs(ans,visited,sr,sc,color,img[sr][sc]);
        return ans;
    }
};