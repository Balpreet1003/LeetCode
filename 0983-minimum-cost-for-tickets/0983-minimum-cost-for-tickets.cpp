class Solution {
    vector<vector<int>>dp;
    int solve(vector<int>&days,vector<int>&costs,int i,int daysLeft){
        if(i>=days.size())return 0;
        if(dp[i][daysLeft]!=-1)return dp[i][daysLeft];
        if(i!=0 && (days[i]-days[i-1])<=daysLeft){
            return dp[i][daysLeft]=solve(days,costs,i+1,daysLeft-(days[i]-days[i-1]));
        }
        return dp[i][daysLeft]=min(costs[0]+solve(days,costs,i+1,0),min(costs[1]+solve(days,costs,i+1,6),costs[2]+solve(days,costs,i+1,29)));
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        dp.resize(days.size()+1,vector<int>(31,INT_MAX));
        for(int i=0;i<31;i++) dp[days.size()][i]=0;
        for(int i=days.size()-1;i>=0;i--){
            for(int daysLeft=30;daysLeft>=0;daysLeft--){
                if(i!=0 && (days[i]-days[i-1])<=daysLeft){
                    dp[i][daysLeft]=dp[i+1][daysLeft-(days[i]-days[i-1])];
                }
                else dp[i][daysLeft]=min(costs[0]+dp[i+1][0],min(costs[1]+dp[i+1][6],costs[2]+dp[i+1][29]));
            }
        }
        return dp[0][0];
    }
};