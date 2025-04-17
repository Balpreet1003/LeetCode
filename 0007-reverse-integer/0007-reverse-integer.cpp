class Solution {
public:
    int reverse(int x) {
        string s = to_string(x);
        bool flag = (x < 0);
        int i = 0, j = s.size() - 1;

        while (i < j) {
            swap(s[i++], s[j--]);
        }
        long long ans = stoll(s);
        if (flag)
            ans *= -1;
        return (ans > INT_MAX || ans < INT_MIN) ? 0 : ans;
    }
};