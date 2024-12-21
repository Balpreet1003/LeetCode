class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                bool cond=true;
                if(i>0 && mat[i-1][j]>=mat[i][j])cond=false;
                if(i<(n-1) && mat[i+1][j]>=mat[i][j])cond=false;
                if(j>0 && mat[i][j-1]>=mat[i][j])cond=false;
                if(j<(m-1) && mat[i][j+1]>=mat[i][j])cond=false;
                if(cond)return {i,j};
            }
        }
        return {-1,-1};
    }
};