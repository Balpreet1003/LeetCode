class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int ans=0, diag=0;
        for(auto x:dimensions){
            int diag1=(x[0]*x[0])+(x[1]*x[1]);
            if(diag1>diag){
                ans=x[0]*x[1];
                diag=diag1;
            }
            else if(diag1==diag){
                ans=max(ans, x[0]*x[1]);
            }
        }
        return ans;
    }
};