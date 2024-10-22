class Solution {
    bool isposs(vector<int>& a, int& mid, int& t) {
        int sum = 0;
        for (int i : a) {
            sum += (i + mid - 1) / mid;
            if (sum > t)
                return false;
        }
        return sum <= t;
    }

public:
    int smallestDivisor(vector<int>& a, int t) {
        int i = 1, j = 0;
        for (int x : a)
            j = max(j, x);
        int ans;
        while (i <= j) {
            int mid = (i + j) / 2;
            if (isposs(a, mid, t)) {
                ans = mid;
                j = mid - 1;
            } else {
                i = mid + 1;
            }
        }
        return ans;
    }
};