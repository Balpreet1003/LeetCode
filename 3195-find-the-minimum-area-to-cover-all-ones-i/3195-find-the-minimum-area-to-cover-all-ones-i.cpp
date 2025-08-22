class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        int min_x=n, min_y=m, max_x=0, max_y=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    min_x=min(min_x, i);
                    min_y=min(min_y, j);
                    max_x=max(max_x, i);
                    max_y=max(max_y, j);
                }
            }
        }
        return (max_y-min_y+1)*(max_x-min_x+1);
    }
};