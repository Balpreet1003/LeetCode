class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                
                if (mat[i][j] == 1 && i > 0) {
                    mat[i][j] += mat[i-1][j];
                }

            
                int minHeight = mat[i][j];
                for (int k = j; k >= 0 && minHeight > 0; k--) {
                    minHeight = min(minHeight, mat[i][k]);
                    ans += minHeight;
                }
            }
        }
        return ans;
    }
};