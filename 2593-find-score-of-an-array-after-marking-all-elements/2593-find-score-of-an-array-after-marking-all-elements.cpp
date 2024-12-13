class Solution {
    class cmd {
    public:
        bool operator()(pair<int, int>& a, pair<int, int>& b) {
            if (a.first == b.first) return a.second > b.second;
            return a.first > b.first;
        }
    };
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmd> pq;
        vector<int> visited(n, 0);

        for (int i = 0; i < n; i++) {
            pq.push({nums[i], i});
        }

        while (!pq.empty()) {
            auto x = pq.top();
            pq.pop();

            int i = x.second;
            long long val = (long long)x.first;

            if (visited[i] == 0) {
                ans += val;
                visited[i] = 1;
                if ((i - 1) >= 0) visited[i - 1] = 1;
                if ((i + 1) < n) visited[i + 1] = 1;
            }
        }

        return ans;
    }
};