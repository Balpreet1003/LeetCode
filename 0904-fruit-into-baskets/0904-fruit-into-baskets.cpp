class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> m;
        int i = 0, n = fruits.size(), ans = 0, sum = 0;
        for (int j = 0; j < n; j++) {
            while (m.size() > 2) {
                m[fruits[i]]--;
                sum--;
                if (m[fruits[i]] == 0) {
                    m.erase(fruits[i]);
                }
                i++;
            }
            ans = max(ans, sum);
            m[fruits[j]]++;
            sum++;
        }
        if (m.size() < 3)
            ans = max(ans, sum);
        return ans;
    }
};