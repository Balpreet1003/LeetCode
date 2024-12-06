class Solution {
public:
    bool canChange(string a, string t) {
        int i = 0, j = 0, n = a.size();
        while (i < n || j < n) {
            while (i < n && a[i] == '_') i++;
            while (j < n && t[j] == '_') j++;
            if (i == n || j == n) return i == n && j == n;
            if (a[i] != t[j]) return false;
            if (a[i] == 'L' && j > i) return false;
            if (a[i] == 'R' && j < i) return false;
            i++;
            j++;
        }
        return true;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();