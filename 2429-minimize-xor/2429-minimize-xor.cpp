class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int cnt = __builtin_popcount(num2);

        int ans = 0;

        for (int i = 31; i >= 0 && cnt > 0; --i) {
            if (num1 & (1 << i)) {
                ans |= (1 << i);
                --cnt;
            }
        }

        for (int i = 0; i <= 31 && cnt > 0; ++i) {
            if (!(ans & (1 << i))) {
                ans |= (1 << i);
                --cnt;
            }
        }

        return ans;
    }
};