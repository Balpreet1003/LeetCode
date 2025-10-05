class Solution {
    int n, m;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& vis, int i, int j) {
        vis[i][j] = true;
        for(int k = 0; k < 4; k++){
            int x = i + dx[k], y = j + dy[k];
            if(x >= 0 && y >= 0 && x < n && y < m && !vis[x][y] && heights[x][y] >= heights[i][j]){
                dfs(heights, vis, x, y);
            }
        }
    }
    
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();
        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));
        
        for(int i = 0; i < n; i++){
            dfs(heights, pacific, i, 0);
            dfs(heights, atlantic, i, m-1);
        }
        for(int j = 0; j < m; j++){
            dfs(heights, pacific, 0, j);
            dfs(heights, atlantic, n-1, j);
        }
        
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(pacific[i][j] && atlantic[i][j])
                    ans.push_back({i, j});
            }
        }
        return ans;
    }
};