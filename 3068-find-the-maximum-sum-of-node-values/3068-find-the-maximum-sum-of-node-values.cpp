class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long sum = 0;
        vector<long long> ans;
        for (int x : nums) {
            sum += x;
            int y = x ^ k;
            ans.push_back(y - x);
        }
        sort(ans.begin(), ans.end());
        reverse(ans.begin(), ans.end());
        
        for (int i = 0; i < ans.size() - 1; i += 2) {
            if (ans[i] + ans[i + 1] <= 0) break;
            sum += ans[i] + ans[i + 1];
        }
        return sum;
    }
};