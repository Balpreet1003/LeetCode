class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == 1) return true;

        for (int i = 0; i + 2*k <= n; i++) {
            bool first = true, second = true;

            // Check first subarray [i, i + k - 1]
            for (int j = i + 1; j < i + k; j++) {
                if (nums[j] <= nums[j - 1]) {
                    first = false;
                    break;
                }
            }

            // Check second subarray [i + k, i + 2*k - 1]
            if (first) {
                for (int j = i + k + 1; j < i + 2*k; j++) {
                    if (nums[j] <= nums[j - 1]) {
                        second = false;
                        break;
                    }
                }
                if (second) return true;
            }
        }

        return false;
    }
};
