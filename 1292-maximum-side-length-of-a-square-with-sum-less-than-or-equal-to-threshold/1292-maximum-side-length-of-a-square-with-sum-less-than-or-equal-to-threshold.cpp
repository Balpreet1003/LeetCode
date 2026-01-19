class Solution {
    int n, m;

    bool is_possible(vector<vector<int>>& mat, int threshold, int len) {
        for (int i = len - 1; i < n; i++) {
            for (int j = len - 1; j < m; j++) {

                int x = (i - len >= 0) ? mat[i - len][j] : 0;
                int y = (j - len >= 0) ? mat[i][j - len] : 0;
                int z = (i - len >= 0 && j - len >= 0) ? mat[i - len][j - len] : 0;

                int sum = mat[i][j] - x - y + z;
                if (sum <= threshold)
                    return true;
            }
        }
        return false;
    }

public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        n = mat.size();
        m = mat[0].size();

        // Row-wise prefix sum
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < m; j++) {
                mat[i][j] += mat[i][j - 1];
            }
        }

        // Column-wise prefix sum
        for (int j = 0; j < m; j++) {
            for (int i = 1; i < n; i++) {
                mat[i][j] += mat[i - 1][j];
            }
        }

        int l = 1, h = min(n, m);
        int ans = 0;

        while (l <= h) {
            int mid = (l + h) / 2;
            if (is_possible(mat, threshold, mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }

        return ans;
    }
};