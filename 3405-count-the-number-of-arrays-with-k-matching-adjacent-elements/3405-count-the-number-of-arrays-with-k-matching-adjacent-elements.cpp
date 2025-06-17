class Solution {
public:
    const int MOD = 1e9 + 7;
    long long power(long long x, long long y) {
        long long result = 1;
        x = x % MOD;
        while (y > 0) {
            if (y & 1) {
                result = (result * x) % MOD;
            }
            x = (x * x) % MOD;
            y = y >> 1;
        }
        return result;
    }

    long long nCr(long long n, long long r) {
        if (r > n) {
            return 0;
        }
        if (r == 0) {
            return 1;
        }

        long long num = 1, den = 1;
        for (long long i = 0; i < r; i++) {
            num = (num * (n - i)) % MOD;
            den = (den * (i + 1)) % MOD;
        }

        return (num * power(den, MOD - 2)) % MOD;
    }
    
    int countGoodArrays(int n, int m, int k) {
        long long kpos = nCr(n - 1, k);
        long long rem = power(m - 1, n - k - 1);
        long long ans = (kpos * m) % MOD;
        ans = (ans * rem) % MOD;

        return (int)ans;
    }
};