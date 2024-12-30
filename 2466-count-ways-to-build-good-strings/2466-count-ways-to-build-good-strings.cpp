class Solution {
    const int MOD=1000000007;
    vector<int>dp;
    int solve(int&l,int&h,int&z,int&o,long long len){
        if(len>h)return 0;
        if(dp[len]!=-1)return dp[len];
        if(len>=l) return dp[len]=(1+solve(l,h,z,o,len+z)+solve(l,h,z,o,len+o))%MOD;
        return dp[len]=(solve(l,h,z,o,len+z)+solve(l,h,z,o,len+o))%MOD;
    }
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        dp.resize(high+1,-1);
        return solve(low,high,zero,one,0);
    }
};