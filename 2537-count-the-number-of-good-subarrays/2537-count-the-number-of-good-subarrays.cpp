#define ll long long
class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        ll ans = 0, cnt = 0;
        unordered_map<int, ll> m;
        int i = 0;

        for (int j = 0; j < n; ++j) {
            cnt += m[nums[j]];
            m[nums[j]]++;

            while (cnt >= k) {
                ans += (n - j);
                m[nums[i]]--;
                cnt -= m[nums[i]]; 
                i++;
            }
        }
        return ans;
    }
};