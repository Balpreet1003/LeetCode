class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int even = 0, odd = 0;

        for(int num : nums) {
            if(num % 2 == 0) even++;
            else odd++;
        }

        if(abs(even - odd) > 1) return -1;

        vector<int> even_pos, odd_pos;
        for(int i = 0; i < n; ++i) {
            if(nums[i] % 2 == 0) even_pos.push_back(i);
            else odd_pos.push_back(i);
        }

        int res = INT_MAX;

        if(even >= odd) {
            int swaps = 0;
            for(int i = 0; i < even_pos.size(); ++i)
                swaps += abs(even_pos[i] - 2 * i);
            res = min(res, swaps);
        }

        if(odd >= even) {
            int swaps = 0;
            for(int i = 0; i < odd_pos.size(); ++i)
                swaps += abs(odd_pos[i] - 2 * i);
            res = min(res, swaps);
        }

        return res;
    }
};