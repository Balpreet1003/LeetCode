class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        stack<int> st;

        for (int x : nums) {
            while (!st.empty() && st.top() > x) {
                st.pop();
                ans++;
            }
            if (x > 0 && (st.empty() || st.top() < x)) {
                st.push(x);
            }
        }

        while (!st.empty()) {
            st.pop();
            ans++;
        }

        return ans;
    }
};