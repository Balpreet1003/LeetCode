class Solution {
    bool isposs(vector<int>& a, int& t, int& mid) {
        int c = 1, sum = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] > mid)
                return false;
            if (sum + a[i] > mid) {
                c++;
                sum = a[i];
            } else
                sum += a[i];
        }
        return c <= t;
    }

public:
    int shipWithinDays(vector<int>& a, int t) {
        int i = 1, j = 0;
        for (int x : a)
            j += x;
        int ans = 0;
        while (i <= j) {
            int mid = (i + j) / 2;
            if (isposs(a, t, mid)) {
                ans = mid;
                j = mid - 1;
            } else {
                i = mid + 1;
            }
        }
        return ans;
    }
};