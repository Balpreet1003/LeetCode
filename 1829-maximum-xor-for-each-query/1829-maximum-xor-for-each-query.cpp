class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> ans;
        int prefixXor = 0;
        int k = (1 << maximumBit) - 1;

        for (int num : nums) {
            prefixXor ^= num;
            ans.push_back(prefixXor ^ k);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};