class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s(nums.begin(), nums.end());
        int totalUnique = s.size();
        
        int ans = 0;
        unordered_map<int, int> m;
        int i = 0;

        for (int j = 0; j < n; j++) {
            m[nums[j]]++;
            while (m.size() == totalUnique) {
                ans += (n - j); 
                m[nums[i]]--;
                if (m[nums[i]] == 0)
                    m.erase(nums[i]);
                i++;
            }
        }
        return ans;
    }
};