class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>prev_arr(n+1,0),curr(n+1,0);
        for (int i = n-1; i >= 0; --i) {
            for (int prev = i-1; prev >= -1; --prev) {
                int notTake = prev_arr[prev+1];
                int take = 0;
                if (prev == -1 || nums[i] > nums[prev]) {
                    take = 1 + prev_arr[i+1];
                }
                curr[prev+1] = max(take, notTake);
            }
            prev_arr=curr;
        }

        return curr[0];
    }
};