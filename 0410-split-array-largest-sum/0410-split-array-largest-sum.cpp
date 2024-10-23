class Solution {
    bool isposs(vector<int>& a, int& k, int& mid) {
        int c = 1, sum = 0;
        for (int i : a) {
            if (i > mid)
                return false;
            if (i + sum > mid) {
                c++;
                sum = i;
            } else {
                sum += i;
            }
        }
        return c <= k;
    }

public:
    int splitArray(vector<int>& a, int k) {
        int i = *max_element(a.begin(), a.end());
        int j = accumulate(a.begin(), a.end(), 0);
        int ans = j;
        while (i <= j) {
            int mid = (i + j) / 2;
            if (isposs(a, k, mid)) {
                ans = mid;
                j = mid - 1;
            } else
                i = mid + 1;
        }
        return ans;
    }
};