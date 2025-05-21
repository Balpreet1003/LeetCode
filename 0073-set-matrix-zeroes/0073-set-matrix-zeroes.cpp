class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n1=matrix.size(),n2=matrix[0].size();
        unordered_map<int,int>mi,mj;
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                if(matrix[i][j]==0){
                    mi[i]=1;
                    mj[j]=1;
                }
            }
        }

        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                if(mi.find(i)!=mi.end() || mj.find(j)!=mj.end())matrix[i][j]=0;
            }
        }
    }
};