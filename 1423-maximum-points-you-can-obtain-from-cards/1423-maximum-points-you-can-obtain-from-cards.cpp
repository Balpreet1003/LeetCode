class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = 0, n = cardPoints.size();
        for(int i = 0; i < k; i++) {
            sum += cardPoints[i];
        }
        int ans = sum;
        int i = k - 1;
        for(int j = n - 1; j > n - k - 1; j--) {
            sum -= cardPoints[i--];
            sum += cardPoints[j];
            ans = max(ans, sum);
        }
        return ans;
    }
};