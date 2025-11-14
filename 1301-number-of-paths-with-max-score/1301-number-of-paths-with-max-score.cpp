class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& arr) {
        int n = arr.size();

        vector<vector<pair<int,int>>> dp(n, vector<pair<int,int>>(n, {INT_MIN, 0}));

        // Starting point (bottom-right)
        dp[n-1][n-1] = {0, 1};

        // Fill from bottom-right to top-left
        for(int i = n-1; i >= 0; i--) {
            for(int j = n-1; j >= 0; j--) {

                if(arr[i][j] == 'X') {
                    dp[i][j] = {INT_MIN, 0};
                    continue;
                }
                
                if(i == n-1 && j == n-1) continue; // Skip end cell

                int maxScore = INT_MIN;
                long long ways = 0;

                // Move down
                if(i + 1 < n && dp[i+1][j].first != INT_MIN) {
                    if(dp[i+1][j].first > maxScore) {
                        maxScore = dp[i+1][j].first;
                        ways = dp[i+1][j].second;
                    } else if(dp[i+1][j].first == maxScore) {
                        ways += dp[i+1][j].second;
                    }
                }

                // Move right
                if(j + 1 < n && dp[i][j+1].first != INT_MIN) {
                    if(dp[i][j+1].first > maxScore) {
                        maxScore = dp[i][j+1].first;
                        ways = dp[i][j+1].second;
                    } else if(dp[i][j+1].first == maxScore) {
                        ways += dp[i][j+1].second;
                    }
                }

                // Move diagonal
                if(i + 1 < n && j + 1 < n && dp[i+1][j+1].first != INT_MIN) {
                    if(dp[i+1][j+1].first > maxScore) {
                        maxScore = dp[i+1][j+1].first;
                        ways = dp[i+1][j+1].second;
                    } else if(dp[i+1][j+1].first == maxScore) {
                        ways += dp[i+1][j+1].second;
                    }
                }

                if(maxScore == INT_MIN) {
                    dp[i][j] = {INT_MIN, 0};
                } else {
                    int val = (i == 0 && j == 0) ? 0 : arr[i][j] - '0';
                    dp[i][j] = {maxScore + val, (int)(ways % 1000000007)};
                }
            }
        }

        if(dp[0][0].first == INT_MIN) return {0, 0};

        return {dp[0][0].first, dp[0][0].second};
    }
};
