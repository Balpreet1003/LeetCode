class Solution {
    static const int len = 1001;  // const so it’s usable at compile-time
    vector<bool> isPrime;
    set<int> ans;

    void get_prime(int n) {
        for (int i = 2; i <= n; i++) {
            if (isPrime[i]) {
                for (long long j = 1LL * i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
    }

    void solve(int n) {
        for (int i = 2; i <= n; i++) {
            if (isPrime[i] && n % i == 0)
                ans.insert(i);
        }
    }

public:
    int distinctPrimeFactors(vector<int>& nums) {
        int n = *max_element(nums.begin(), nums.end());
        isPrime.assign(n + 1, true);
        get_prime(n);

        for (int x : nums) {
            solve(x);
        }
        return ans.size();
    }
};