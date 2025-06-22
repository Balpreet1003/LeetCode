class Solution {
public:
    vector<int> findCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        vector<long long> a(n+1, 0);
        a[0] = 1;

        int i = 1;
        while (i <= n) {
            int x = nums[i-1];
            if (a[i] > x) return {};
            if (a[i] < x) {
                ans.push_back(i);
                int j = i;
                while (j <= n) {
                    a[j] += a[j - i];
                    j++;
                }
            }
            i++;
        }

        i = 1;
        while (i <= n) {
            if (a[i] != nums[i-1]) return {};
            i++;
        }

        return ans;
    }
};