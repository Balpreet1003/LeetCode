class Solution {
    long long cnt_pos(vector<int>& nums, int x, long long mid) {
        int i = 0, j = nums.size();
        while (i < j) {
            int m = (i + j) / 2;
            if (1LL * x * nums[m] <= mid) {
                i = m + 1;
            } else {
                j = m;
            }
        }
        return i;  // Number of elements satisfying the condition
    }

    long long cnt_neg(vector<int>& nums, int x, long long mid) {
        int i = 0, j = nums.size();
        while (i < j) {
            int m = (i + j) / 2;
            if (1LL * x * nums[m] <= mid) {
                j = m;
            } else {
                i = m + 1;
            }
        }
        return nums.size() - i;
    }

    long long get_cnt(vector<int>& nums1, vector<int>& nums2, long long mid) {
        long long count = 0;
        for (int x : nums1) {
            if (x == 0) {
                if (mid >= 0) count += nums2.size();
            } else if (x > 0) {
                count += cnt_pos(nums2, x, mid);
            } else {
                count += cnt_neg(nums2, x, mid);
            }
        }
        return count;
    }

public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long left = -1e10 - 5, right = 1e10 + 5;
        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (get_cnt(nums1, nums2, mid) < k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};