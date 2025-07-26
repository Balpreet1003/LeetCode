class Solution {
    const int MOD = 1e9 + 7;
    vector<vector<long long>> ncr;

    long long dfs(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) {
            return 1;
        }

        vector<int> left, right;
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[0]) {
                left.push_back(nums[i]);
            } else {
                right.push_back(nums[i]);
            }
        }

        long long l = dfs(left) % MOD;
        long long r = dfs(right) % MOD;

        return ((ncr[n - 1][left.size()] * l) % MOD * r) % MOD;
    }

public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        ncr.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            ncr[i] = vector<long long>(i + 1, 1);
            for (int j = 1; j < i; j++) {
                ncr[i][j] = (ncr[i - 1][j - 1] + ncr[i - 1][j]) % MOD;
            }
        }
        long long ans = dfs(nums);
        return (ans - 1 + MOD) % MOD;
    }
};