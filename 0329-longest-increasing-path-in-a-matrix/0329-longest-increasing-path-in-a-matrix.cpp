class Solution {
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    vector<vector<int>>dp;
    int dfs(vector<vector<int>>&matrix, int i,int j){
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=0;
        for(int x=0;x<4;x++){
            int x1=i+dx[x], y1=j+dy[x];
            if(x1<matrix.size() && x1>=0 && y1<matrix[0].size() && y1>=0 && matrix[x1][y1]>matrix[i][j]){
                int temp=matrix[i][j];
                matrix[i][j]=-1;
                ans=max(ans,dfs(matrix,x1,y1)+1);
                matrix[i][j]=temp;
            }
        }
        return dp[i][j] = ans;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans=1;
        int n=matrix.size(),m=matrix[0].size();
        dp.resize(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dp[i][j]==-1){
                    dfs(matrix,i,j);
                }
                ans=max(ans,dp[i][j]+1);
            }
        }
        return ans;
    }
};