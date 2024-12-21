class Solution {
    int maxi(vector<vector<int>>&mat,int j){
        int ans=0;
        for(int i=1;i<mat.size();i++){
            if(mat[i][j]>mat[ans][j])ans=i;
        }
        return ans;
    }
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        if(n==1 && m==1)return {0,0};
        if(m==1){
            return {maxi(mat,0),0};
        }
        int i=0,j=m-1;
        while(i<=j){
            int mid=(j+i)/2;
            int x=maxi(mat,mid);
            if(mid==0){
                if(mat[x][mid]>mat[x][mid+1])return {x,mid};
                else i=mid+1;
            }
            else if(mid==m-1){
                if(mat[x][mid]>mat[x][mid-1])return {x,mid};
                else j=mid-1;
            }
            else {
                if(mat[x][mid]>mat[x][mid-1] && mat[x][mid]>mat[x][mid+1])return {x,mid};
                else if(mat[x][mid]<mat[x][mid-1])j=mid-1;
                else j=mid+1;
            }
        }
        return {-1,-1};
    }
};