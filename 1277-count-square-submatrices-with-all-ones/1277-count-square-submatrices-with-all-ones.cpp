class Solution {
    vector<vector<int>>dp;
    int helper(vector<vector<int>>& mat, int i, int j) {
        if (i < 0 || j < 0 || mat[i][j] == 0) 
            return 0;
        if (dp[i][j]!=-1) 
            return dp[i][j];

        return dp[i][j] = 1 + min({ helper(mat, i-1, j), 
                         helper(mat, i, j-1), 
                         helper(mat, i-1, j-1) });
    }

public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;
        
        dp.resize(n+1, vector<int>(m+1, -1));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans += helper(matrix, i, j);
            }
        }
        return ans;
    }
};
