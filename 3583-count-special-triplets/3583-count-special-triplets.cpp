class Solution {
    const int MOD = 1e9 + 7;

public:
    int specialTriplets(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, pair<int, int>> m;
        for (int i : nums) {
            if (m.find(i) == m.end())
                m[i] = {1, 0};
            else
                m[i].first++;
            if (i != 0 && m[i].first > 1 && !(i & 1) &&
                m.find(i / 2) != m.end()) {
                ans = (ans + m[i / 2].second) % MOD;
            }
            if (m.find(i * 2) != m.end()) {
                m[i].second = (m[i].second + m[i * 2].first) % MOD;
            }
        }
        if (m.find(0) != m.end() && m[0].first >= 3) {
            long long n = m[0].first;
            long long triplets = (n * (n - 1) % MOD * (n - 2) % MOD) * 166666668LL % MOD;
            ans = (ans + triplets) % MOD;
        }
        return ans;
    }
};
