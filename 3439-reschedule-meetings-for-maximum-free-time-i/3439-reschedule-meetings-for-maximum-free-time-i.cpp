class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime,
                    vector<int>& endTime) {
        vector<int> nums;
        int n = startTime.size();
        if (startTime[0] > 0)
            nums.push_back(startTime[0] - 0);
        for (int i = 1; i < n; i++) {
            nums.push_back(startTime[i] - endTime[i - 1]);
        }
        if (endTime[n - 1] < eventTime)
            nums.push_back(eventTime - endTime[n - 1]);
        int ans = 0;
        int i = 0, j = 0, sum = 0;
        while (j < nums.size()) {
            if ((j - i + 1) <= (k + 1)) {
                sum += nums[j];
                j++;
            } else {
                sum -= nums[i];
                i++;
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};