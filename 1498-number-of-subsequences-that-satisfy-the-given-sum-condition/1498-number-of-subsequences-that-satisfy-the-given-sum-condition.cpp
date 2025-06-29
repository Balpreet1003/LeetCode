class Solution {
    const int MOD = 1e9 + 7;

    // Fast exponentiation
    int power(int base, int exp) {
        long long result = 1;
        long long b = base;
        while (exp > 0) {
            if (exp % 2 == 1) result = (result * b) % MOD;
            b = (b * b) % MOD;
            exp /= 2;
        }
        return result;
    }

public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        // Precompute powers of 2 up to n
        vector<int> pow2(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            pow2[i] = (pow2[i - 1] * 2LL) % MOD;
        }

        int left = 0, right = n - 1;
        int ans = 0;

        while (left <= right) {
            if (nums[left] + nums[right] <= target) {
                ans = (ans + pow2[right - left]) % MOD;
                left++;
            } else {
                right--;
            }
        }

        return ans;
    }
};