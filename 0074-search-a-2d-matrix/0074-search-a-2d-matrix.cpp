class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int t) {
        int n=a.size(),m=a[0].size();
        int i=0,j=m*n-1;
        while(i<=j){
            int mid=(i+j)/2;
            int r=mid/m,c=mid%m;
            if(a[r][c]==t)return 1;
            else if(a[r][c]>t){
                j=mid-1;
            }
            else {
                i=mid+1;
            }
        }
        return 0;
    }
};