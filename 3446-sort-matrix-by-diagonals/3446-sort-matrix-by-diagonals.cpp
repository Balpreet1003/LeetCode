class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        vector<vector<int>>ans=grid;
        int n=grid.size();
        //for the first top-right triangle
        for(int x=1;x<n-1;x++){
            vector<int>temp;
            int i=0,j=x;
            while(i<n && j<n){
                temp.push_back(grid[i++][j++]);
            }
            sort(temp.begin(), temp.end());
            i=0; j=x;
            int k=0;
            while(i<n && j<n){
                ans[i++][j++]=temp[k++];
            }
        }
        //for the bottom-left tringle
        for(int x=0;x<n-1;x++){
            vector<int>temp;
            int i=x, j=0;
            while(i<n && j<n){
                temp.push_back(grid[i++][j++]);
            }
            sort(temp.begin(), temp.end());
            i=x; j=0;
            int k=temp.size()-1;
            while(i<n && j<n){
                ans[i++][j++]=temp[k--];
            }
        }
        return ans;
    }
};