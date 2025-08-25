class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = (int)mat.size();
        if (m == 0) return {};
        int n = (int)mat[0].size();

        vector<int> ans;
        ans.reserve(m * n);

        for (int d = 0; d <= m + n - 2; ++d) {
            if (d % 2 == 0) {
                int r = min(d, m - 1);
                int c = d - r;
                while (r >= 0 && c < n) {
                    ans.push_back(mat[r][c]);
                    --r; ++c;
                }
            } else {
                int c = min(d, n - 1);
                int r = d - c;
                while (c >= 0 && r < m) {
                    ans.push_back(mat[r][c]);
                    ++r; --c;
                }
            }
        }
        return ans;
    }
};
