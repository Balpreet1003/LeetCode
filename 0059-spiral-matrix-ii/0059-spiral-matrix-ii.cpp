class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>ans(n,vector<int>(n,0));
        int x=1, l=0, r=n-1, u=0, d=n-1;

        while(l<=r && u<=d){
            int i=u,j=l;
            for(;j<=r;j++)ans[i][j]=x++;
            u++;
            if(u>d)break;

            i=u;j=r;
            for(;i<=d;i++)ans[i][j]=x++;
            r--;
            if(l>r)break;
            
            i=d;j=r;
            for(;j>=l;j--)ans[i][j]=x++;
            d--;
            if(u>d)break;

            i=d;j=l;
            for(;i>=u;i--)ans[i][j]=x++;
            l++;
        }
        
        return ans;
    }
};