class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        map<int, int>m;
        unordered_map<int, long long>dp;
        for(int i:power)m[i]++;

        long long ans=0, prev_ele, back_ele=0;
        for(auto [x, y]:m){
            auto back_it=m.lower_bound(x-2);
            if(back_it!=m.begin())back_ele=(*(--back_it)).first;
            dp[x]=max(dp[prev_ele], x*y + dp[back_ele]);
            ans=max(ans, dp[x]);
            prev_ele=x;
        }
        return ans;
    }
};