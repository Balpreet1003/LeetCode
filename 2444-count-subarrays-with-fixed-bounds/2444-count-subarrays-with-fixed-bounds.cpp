class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int badIdx = -1, l = -1, r = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (!(minK <= nums[i] && nums[i] <= maxK)) {
                badIdx = i;
            }
            if (nums[i] == minK) {
                l = i;
            }
            if (nums[i] == maxK) {
                r = i;
            }
            ans += max(0, min(l, r) - badIdx);
        }
        return ans; 
    }
};