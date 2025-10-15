class Solution {
    bool is_poss(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == 1) return true;

        int prev = 0;
        int len = 1;

        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                len++;
            } else {
                if ((prev >= k && len >= k) || len>=2*k)
                    return true;
                prev = len;
                len = 1;
            }
        }

        if ((prev >= k && len >= k) || len>=2*k)
            return true;

        return false;
    }

public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int ans = 0;
        int l = 1, h = (nums.size() / 2) + 1; // l starts from 1 (since k>=1)

        while (l <= h) {
            int mid = (l + h) / 2;
            if (is_poss(nums, mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        return ans;
    }
};