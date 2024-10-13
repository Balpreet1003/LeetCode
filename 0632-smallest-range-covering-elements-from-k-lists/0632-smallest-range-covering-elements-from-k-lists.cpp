class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& a) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            mh;
        int maxi = numeric_limits<int>::min();
        for (int i = 0; i < a.size(); i++) {
            mh.push({a[i][0], i, 0});
            maxi = max(maxi, a[i][0]);
        }
        vector<int> ans = {0, numeric_limits<int>::max()};
        while (!mh.empty()) {
            vector<int> x = mh.top();
            mh.pop();
            int mini = x[0], i = x[1], j = x[2];
            if (maxi - mini < ans[1] - ans[0]) {
                ans[0] = mini;
                ans[1] = maxi;
            }
            if (j + 1 < a[i].size()) {
                int x = a[i][j + 1];
                mh.push({x, i, j + 1});
                maxi = max(maxi, x);
            } else
                break;
        }
        return ans;
    }
};