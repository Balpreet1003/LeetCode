class Solution {
public:
    int coinChangeSolver(vector<int>&coins,int amount){
        vector<int>dp(amount+1,INT_MAX);
        dp[0]=0;
        for(int target=1;target<=amount;target++){
            int mini=INT_MAX;
            int count=INT_MAX;
            for(int i=0;i<coins.size();i++){
                if(target-coins[i]>=0)
                    count=dp[target-coins[i]];
                if(count !=INT_MAX){
                    mini=min(mini,count+1);
                }
            }
            dp[target]=mini;
        }
        return dp[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        int ans = coinChangeSolver(coins,amount);
        if(ans != INT_MAX)
            return ans;
        else
            return -1;
    }
};