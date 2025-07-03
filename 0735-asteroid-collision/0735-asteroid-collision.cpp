class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for (int ast : asteroids) {
            bool destroyed = false;
            while (!st.empty() && ast < 0 && st.top() > 0) {
                if (st.top() < -ast) {
                    st.pop();
                    continue;
                } else if (st.top() == -ast) {
                    st.pop();
                }
                destroyed = true;
                break;
            }
            if (!destroyed)
                st.push(ast);
        }
        vector<int> res(st.size());
        for (int i = st.size() - 1; i >= 0; --i) {
            res[i] = st.top();
            st.pop();
        }
        return res;
    }
};