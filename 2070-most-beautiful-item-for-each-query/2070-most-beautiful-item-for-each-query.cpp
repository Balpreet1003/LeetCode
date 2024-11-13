class Solution {
    static bool cmd(vector<int>& a, vector<int>& b) {
        return a[0] < b[0];
    }
public:
    vector<int> maximumBeauty(vector<vector<int>>& a, vector<int>& b) {
        vector<int> ans;
        
        // Sort 'a' by price in ascending order
        sort(a.begin(), a.end(), cmd);

        // Precompute the maximum beauty for each price in 'a'
        for (int i = 1; i < a.size(); i++) {
            a[i][1] = max(a[i][1], a[i-1][1]);
        }
        
        // For each price 't' in 'b', use binary search to find the maximum beauty
        for (int t : b) {
            int i = 0, j = a.size() - 1;
            int x = 0;
            while (i <= j) {
                int mid = (i + j) / 2;
                if (a[mid][0] <= t) {
                    x = a[mid][1]; // Store the max beauty up to this price
                    i = mid + 1;
                } else {
                    j = mid - 1;
                }
            }
            ans.push_back(x);
        }
        
        return ans;
    }
};