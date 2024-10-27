class Solution {
    long long lcm(long long a, long long b) {
        return (a / gcd(a, b)) * b;
    }
    long long solve1(vector<int>& nums) {
        long long ans = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            ans = lcm(ans, (long long)nums[i]);
        }
        return ans;
    }
    long long solve2(vector<int>& nums) {
        long long ans = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            ans = gcd(ans, (long long)nums[i]);
        }
        return ans;
    }
public:
    long long maxScore(std::vector<int>& a) {
        int n = a.size();
        if (n == 1) return a[0]*a[0]; 

        long long ans = solve2(a) * solve1(a);
        for (int i = 0; i < n; i++) {
            vector<int> b;
            for (int j = 0; j < n; j++) {
                if (i != j) b.push_back(a[j]);
            }
            long long x = (long long)solve2(b) * (long long)solve1(b);
            ans = max(ans, x);
        }
        return ans;
    }
};