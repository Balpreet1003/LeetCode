class Solution {
public:
    void setZeroes(vector<vector<int>>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);

        int n=nums.size(),m=nums[0].size();
        unordered_map<int,int>row,col;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(nums[i][j]==0){
                    row[i]=1;
                    col[j]=1;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(row.find(i)!=row.end())nums[i][j]=0;
                if(col.find(j)!=col.end())nums[i][j]=0;
            }
        }
    }
};