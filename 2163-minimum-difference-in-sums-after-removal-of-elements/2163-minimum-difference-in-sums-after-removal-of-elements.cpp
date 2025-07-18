class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size();
        vector<long long> max_sum(n, 0), min_sum(n, 0);
        priority_queue<int> maxi;
        priority_queue<int, vector<int>, greater<int>> mini;
        long long sum = 0;

        for (int i = n - 1; i >= (n / 3); i--) {
            mini.push(nums[i]);
            sum += nums[i];
            while (mini.size() > (n / 3)) {
                sum -= mini.top();
                mini.pop();
            }
            if (mini.size() == (n / 3)) {
                max_sum[i] = sum;
            }
        }
        sum = 0;
        for (int i = 0; i < ((n * 2) / 3); i++) {
            maxi.push(nums[i]);
            sum += nums[i];
            while (maxi.size() > (n / 3)) {
                sum -= maxi.top();
                maxi.pop();
            }
            if (maxi.size() == (n / 3)) {
                min_sum[i] = sum;
            }
        }
        for (auto i : max_sum) {
            cout << i << " ";
        }
        cout << endl;
        for (auto i : min_sum) {
            cout << i << " ";
        }
        cout << endl;
        long long ans = LLONG_MAX;
        for (int i = (n / 3); i <= ((2 * n) / 3); i++) {
            cout << i << " ";
            ans = min(ans, min_sum[i-1] - max_sum[i]);
        }
        return ans;
    }
};