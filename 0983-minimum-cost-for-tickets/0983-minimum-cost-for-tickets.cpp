class Solution {
private:
    int minCost(vector<int>&days,vector<int>& costs,int i,int reserveDays,vector<vector<int>>& dp){
        //bc
        if(i>=days.size())
            return 0;
        
        if(dp[i][reserveDays]!=-1)
            return dp[i][reserveDays];
        //1 case solve karo
        if(i!=0 && (days[i]-days[i-1])<=reserveDays){
            return dp[i][reserveDays]= minCost(days,costs,i+1,reserveDays-(days[i]-days[i-1]),dp);
        }
        return dp[i][reserveDays]= min(costs[0]+minCost(days,costs,i+1,0,dp),min(costs[1]+minCost(days,costs,i+1,6,dp),costs[2]+minCost(days,costs,i+1,29,dp)));
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<vector<int>>dp(days.size()+1,vector<int>(31,INT_MAX));

        for(int i=0;i<31;i++){
            dp[days.size()][i]=0;
        }

        for(int i=days.size()-1;i>=0;i--){
            for(int j=30;j>=0;j--){
                if(i!=0 && (days[i]-days[i-1])<=j){
                    dp[i][j]= dp[i+1][j-(days[i]-days[i-1])];
                }
                else
                    dp[i][j]= min(costs[0]+dp[i+1][0],min(costs[1]+dp[i+1][6],costs[2]+dp[i+1][29]));
            }
        }
        return dp[0][0];
    }
};