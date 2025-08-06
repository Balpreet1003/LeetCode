class Solution {
    vector<string> ans;

    void solve(string& s, int target, int pos, long long output, long long prev_num, string expr) {
        if (pos == s.length()) {
            if (output == target)
                ans.push_back(expr);
            return;
        }

        for (int i = pos; i < s.length(); i++) {
            if (i != pos && s[pos] == '0') break;
            string curr_str = s.substr(pos, i - pos + 1);
            long long curr_num = stoll(curr_str);

            if (pos == 0) {
                solve(s, target, i + 1, curr_num, curr_num, curr_str);
            } else {
                solve(s, target, i + 1, output + curr_num, curr_num, expr + "+" + curr_str);
                solve(s, target, i + 1, output - curr_num, -curr_num, expr + "-" + curr_str);
                solve(s, target, i + 1, output - prev_num + prev_num * curr_num, prev_num * curr_num, expr + "*" + curr_str);
            }
        }
    }

public:
    vector<string> addOperators(string num, int target) {
        ans.clear();
        solve(num, target, 0, 0, 0, "");
        return ans;
    }
};