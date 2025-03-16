#define ll long long
class Solution {
    bool isPossible(vector<int>& ranks, int n, ll x) {
        ll cnt = 0;
        for (int i : ranks) {
            cnt += sqrt(x / i);
            if (cnt >= n) return true;
        }
        return cnt >= n;
    }

public:
    long long repairCars(vector<int>& ranks, int n) {
        ll i = 1, j = LLONG_MAX;

        for (int x : ranks) {
            j = max(j, (ll)x * n * n);
        }

        ll ans = j;
        while (i <= j) {
            ll mid = i + (j - i) / 2;

            if (isPossible(ranks, n, mid)) {
                ans = mid;
                j = mid - 1;
            } else {
                i = mid + 1;
            }
        }

        return ans;
    }
};
