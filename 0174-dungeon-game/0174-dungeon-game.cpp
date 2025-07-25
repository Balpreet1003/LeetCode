class Solution {
    int n,m;
    vector<vector<int>>dp;
    int solve(vector<vector<int>>&dungeon,int i,int j){
        if(i>=n || j>=m){
            return INT_MAX;
        }
        if(i==n-1 && j==m-1){
            return dp[i][j]=max(1,1-dungeon[i][j]);
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int op1 = solve(dungeon,i+1,j);
        int op2 = solve(dungeon,i,j+1);

        return dp[i][j]=max(1, min(op1,op2)-dungeon[i][j]);
    }
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        n=dungeon.size(),m=dungeon[0].size();
        dp.resize(n+1,vector<int>(m+1,100000));

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){  
                if(i==n-1 && j==m-1){
                    dp[n-1][m-1]=max(1, 1-dungeon[n-1][m-1]);
                    continue;
                }  
                int op1 = dp[i+1][j];
                int op2 = dp[i][j+1];
                dp[i][j]=max(1, min(op1,op2)-dungeon[i][j]);
            }
        }

        return dp[0][0];
    }
};