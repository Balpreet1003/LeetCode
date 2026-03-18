class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        for(auto &x:grid){
            for(int i=1;i<x.size();i++){
                x[i]+=x[i-1];
            }
        }
        int ans=0;
        for(int i=0;i<grid[0].size();i++){
            int sum=0;
            for(int j=0;j<grid.size();j++){
                if(sum+grid[j][i]<=k){
                    ans++;
                    sum+=grid[j][i];
                }
                else{
                    break;
                }
            }
        }
        return ans;
    }
};