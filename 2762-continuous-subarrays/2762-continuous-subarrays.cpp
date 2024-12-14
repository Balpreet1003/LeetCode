class Solution {
    struct cmd1 {
        bool operator()(pair<int, int> a, pair<int, int> b) {
            if (a.first == b.first) return a.second > b.second;
            return a.first < b.first;
        }
    };
    struct cmd2 {
        bool operator()(pair<int, int> a, pair<int, int> b) {
            if (a.first == b.first) return a.second > b.second;
            return a.first > b.first;
        }
    };

public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmd1> pq1;
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmd2> pq2;
        
        int i = 0, j = 0;
        long long ans = 0;
        
        while (j < n) {
            pq1.push({nums[j], j});
            pq2.push({nums[j], j});
            
            while (!pq1.empty() && pq1.top().second < i) pq1.pop();
            while (!pq2.empty() && pq2.top().second < i) pq2.pop();
            
            if (abs(pq1.top().first - pq2.top().first) <= 2) {
                j++;
            } else {
                ans += (j - i);
                i++;
            }
        }
        
        while (i < n) {
            ans += (j - i);
            i++;
        }
        
        return ans;
    }
};