class Solution {
    vector<vector<int>>dp;
    bool solve(vector<int>& stones, int i, int k){
        if(i>=stones.size()-1)
            return true;
        if(k<0)
            return false;
        if(dp[i][k]!=-1){
            return dp[i][k];
        }
        bool ans=false;
        int dx[3]={-1, 0, 1};
        for(int j=i+1;j<stones.size();j++){
            for(int l=0;l<3;l++){
                if(stones[j]-stones[i]==k+dx[l]){
                    ans|=solve(stones, j, k+dx[l]);
                }
            }
        }
        return dp[i][k]=ans;
    }
public:
    bool canCross(vector<int>& stones) {
        int n=stones.size();
        dp.resize(n+1, vector<int>(n+1, -1));
        return stones[1]==1 ? solve(stones, 1, 1) : false;
    }
};