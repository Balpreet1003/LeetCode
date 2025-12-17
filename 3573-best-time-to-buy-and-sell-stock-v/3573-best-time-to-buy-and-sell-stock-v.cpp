#define ll long long
#define pb push_back
#define ld long double
#define vi vector<long long>
class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n=prices.size();
        vi ans(n,0);
        for(int t=1;t<=k;t++) {
            vi curr_ans(n, 0);
            ll x = LLONG_MIN;
            ll y = LLONG_MIN;
            for (int i = 1; i < n; ++i){
                ll z = (i > 1) ? ans[i - 2] : 0;
                x = max(x, z - prices[i - 1]);
                y = max(y, z + prices[i - 1]);
                curr_ans[i] = max(curr_ans[i - 1], max((ll)prices[i] + x, (ll)-prices[i] + y));
            }
            ans = curr_ans;
        }
        return ans[n - 1];
    }
};