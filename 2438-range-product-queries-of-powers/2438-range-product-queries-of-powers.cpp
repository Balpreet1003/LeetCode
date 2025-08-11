class Solution {
    const int MOD = 1e9 + 7;
    long long modpow(long long a, long long e) {
        long long r = 1;
        while (e) {
            if (e & 1)
                r = (r * a) % MOD;
            a = (a * a) % MOD;
            e >>= 1;
        }
        return r;
    }
    long long inv(long long a) { return modpow(a, MOD - 2); }

public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<long long> power;
        int i = 0;
        while (n) {
            if (n & 1) {
                power.push_back(1LL * (1 << i));
            }
            i++;
            n >>= 1;
        }
        for (int i = 1; i < power.size(); i++) {
            power[i] = ((power[i] * power[i - 1]) % MOD);
        }
        vector<int> ans;
        for (auto x : queries) {
            if (x[0] == 0) {
                ans.push_back(power[x[1]] % MOD);
            } else {
                ans.push_back((power[x[1]] * inv(power[x[0] - 1])) % MOD);
            }
        }
        return ans;
    }
};