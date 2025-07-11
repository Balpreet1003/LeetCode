class Solution {
    struct cmp {
        bool operator()(pair<long long, int>& a, pair<long long, int>& b) {
            return (a.first == b.first) ? a.second > b.second : a.first > b.first;
        }
    };

public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        
        priority_queue<int, vector<int>, greater<int>> available;
        for (int i = 0; i < n; i++) available.push(i);

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, cmp> occupied;

        vector<int> cnt(n, 0);

        for (auto& m : meetings) {
            long long start = m[0], end = m[1];
            
            while (!occupied.empty() && occupied.top().first <= start) {
                available.push(occupied.top().second);
                occupied.pop();
            }

            if (!available.empty()) {
                int room = available.top(); available.pop();
                occupied.push({end, room});
                cnt[room]++;
            } else {
                auto [time, room] = occupied.top();
                occupied.pop();
                occupied.push({time + (end - start), room});
                cnt[room]++;
            }
        }

        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (cnt[i] > cnt[ans]) ans = i;
        }
        return ans;
    }
};