class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>> a(n + 1, vector<int>(2, 0));
        for (int i = 0; i < trust.size(); i++) {
            a[trust[i][0]][0]++;
            a[trust[i][1]][1]++;
        }
        int cnt = 0, ans = -1;
        for (int i = 1; i <= n; i++) {
            if (a[i][0] == 0 && a[i][1] == n - 1)
                cnt++, ans = i;
        }
        return cnt > 1 ? -1 : ans;
    }
};