class Solution {
    int n, m;
    bool poss(int i, int j, vector<vector<int>>& mat){
        for(int k=0;k<n;k++){
            if(k!=i && mat[k][j]==1)
                return false;
        }
        for(int k=0;k<m;k++){
            if(k!=j && mat[i][k]==1)
                return false;
        }
        return true;
    }
public:
    int numSpecial(vector<vector<int>>& mat) {
        int ans=0;
        n=mat.size(), m=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1 && poss(i, j, mat))
                    ans++;
            }
        }
        return ans;
    }
};