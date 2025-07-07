class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        for (char task : tasks)
            freq[task]++;

        priority_queue<int> maxHeap;
        for (auto& p : freq)
            maxHeap.push(p.second);

        queue<pair<int, int>> cooldownQueue;
        int time = 0;

        while (!maxHeap.empty() || !cooldownQueue.empty()) {
            time++;

            if (!maxHeap.empty()) {
                int currFreq = maxHeap.top();
                maxHeap.pop();
                currFreq--;

                if (currFreq > 0)
                    cooldownQueue.push({currFreq, time + n});
            }

            if (!cooldownQueue.empty() && cooldownQueue.front().second == time) {
                maxHeap.push(cooldownQueue.front().first);
                cooldownQueue.pop();
            }
        }

        return time;
    }
};