class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        string s_max = s, s_min = s;

        // Maximizing number
        char to_replace_max = '\0';
        for (char c : s) {
            if (c != '9') {
                to_replace_max = c;
                break;
            }
        }
        if (to_replace_max != '\0') {
            for (char &c : s_max) {
                if (c == to_replace_max) c = '9';
            }
        }

        // Minimizing number
        char to_replace_min = '\0';
        if (s[0] != '1') {
            to_replace_min = s[0];
            for (char &c : s_min) {
                if (c == to_replace_min) c = '1';
            }
        } else {
            for (int i = 1; i < s.size(); i++) {
                if (s[i] != '0' && s[i] != '1') {
                    to_replace_min = s[i];
                    break;
                }
            }
            if (to_replace_min != '\0') {
                for (int i = 0; i < s.size(); i++) {
                    if (s_min[i] == to_replace_min) s_min[i] = '0';
                }
            }
        }

        int maxi = stoi(s_max);
        int mini = stoi(s_min);

        return maxi - mini;
    }
};