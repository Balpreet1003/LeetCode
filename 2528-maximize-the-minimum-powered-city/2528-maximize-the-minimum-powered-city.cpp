#define ll long long
class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        vector<ll> diff(n, 0);

        for (int i = 0; i < n; i++) {
            diff[max(0, i - r)] += stations[i];
            if (i + r + 1 < n)
                diff[i + r + 1] -= stations[i];
        }

        auto is_possible = [&](ll tar) {
            ll x = 0, curr_k = k;
            vector<ll> temp = diff;

            for (int i = 0; i < n; i++) {
                x += temp[i];
                if (x < tar) {
                    ll add = tar - x;
                    if (add > curr_k)
                        return false;
                    curr_k -= add;
                    x += add;
                    if (i + 2 * r + 1 < n)
                        temp[i + 2 * r + 1] -= add;
                }
            }
            return true;
        };

        ll l = *min_element(diff.begin(), diff.end());
        ll h = accumulate(stations.begin(), stations.end(), 0LL) + 1LL * k;
        ll ans = -1;

        while (l <= h) {
            ll mid = (l + h) / 2;
            if (is_possible(mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        return ans;
    }
};