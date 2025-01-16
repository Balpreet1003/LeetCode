class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        
        if ((n & 1) == 0 && (m & 1) == 0) {
            return 0;
        }

        if ((n & 1) == 0 && (m & 1) == 1) {
            int ans = 0;
            for (int num : nums1) ans ^= num;
            return ans;
        }

        if ((n & 1) == 1 && (m & 1) == 0) {
            int ans = 0;
            for (int num : nums2) ans ^= num;
            return ans;
        }

        int ans = 0;
        for (int num : nums1) ans ^= num;
        for (int num : nums2) ans ^= num;
        return ans;
    }
};