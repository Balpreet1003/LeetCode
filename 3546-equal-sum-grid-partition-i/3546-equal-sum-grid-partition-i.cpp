class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        vector<vector<long long>>nums(n, vector<long long>(m, 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(j==0)nums[i][j]=grid[i][j];
                else nums[i][j]=grid[i][j]+nums[i][j-1];
            }
        }   
        for(int i=0;i<m;i++){
            for(int j=1;j<n;j++){
                nums[j][i]+=nums[j-1][i];
            }
        }
        for(int i=0;i<n-1;i++){
            if((nums[i][m-1]*2)==nums[n-1][m-1])
                return true;
        }
        for(int j=0;j<m-1;j++){
            if(nums[n-1][j]*2==nums[n-1][m-1])
                return true;
        }
        return false;
    }
};