class Solution {
public:
    int punishmentNumber(int n) {
        vector<int> a = {1,   9,   10,  36,  45,  55,  82,  91,  99,  100,
                         235, 297, 369, 370, 379, 414, 657, 675, 703, 756,
                         792, 909, 918, 945, 964, 990, 991, 999, 1000};
        int ans = 0;
        for (int i = 0; i < 29; i++) {
            if (a[i] <= n) {
                ans += a[i] * a[i];
            } else {
                break;
            }
        }
        return ans;
    }
};