class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> m;
        for (int i : answers)
            m[i]++;

        int ans = 0;
        for (auto& [a, b] : m) {
            if (a == 0)
                ans += b;
            else {
                if (b > (a + 1)) {
                    ans += ((a + 1) * (b / (a + 1)));
                    if(b%(a+1)!=0)ans+=a+1;
                } else {
                    ans += (a + 1);
                }
            }
        }
        return ans;
    }
};