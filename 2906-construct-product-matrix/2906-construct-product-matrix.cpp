class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int mod = 12345;

        vector<int> arr;
        for (auto &row : grid) {
            for (auto &x : row) {
                arr.push_back(x % mod);
            }
        }

        int size = arr.size();
        vector<int> prefix(size, 1), suffix(size, 1);

        // prefix
        for (int i = 1; i < size; i++) {
            prefix[i] = (prefix[i - 1] * arr[i - 1]) % mod;
        }

        // suffix
        for (int i = size - 2; i >= 0; i--) {
            suffix[i] = (suffix[i + 1] * arr[i + 1]) % mod;
        }

        // build answer
        vector<vector<int>> ans(n, vector<int>(m));
        int k = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[i][j] = (prefix[k] * suffix[k]) % mod;
                k++;
            }
        }

        return ans;
    }
};