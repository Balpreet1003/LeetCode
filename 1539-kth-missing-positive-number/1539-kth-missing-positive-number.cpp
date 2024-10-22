class Solution {
public:
    int findKthPositive(vector<int>& a, int k) {
        int i = 0, j = a.size() - 1;
        while (i <= j) {
            int mid = (i + j) / 2;
            if (a[mid] - (mid + 1) >= k) {
                j = mid - 1;
            } else {
                i = mid + 1;
            }
        }
        if (j == -1)
            return k;
        return a[j] + (k - (a[j] - (j + 1)));
    }
};