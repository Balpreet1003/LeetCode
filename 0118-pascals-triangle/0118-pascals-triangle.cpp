class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans(numRows);
        for(int i=0;i<numRows;i++){
            vector<int>a(i+1);
            for(int j=0;j<=i;j++){
                if(j==0){
                    a[j]=1;
                }
                else if(j==i){
                    a[j]=1;
                }
                else{
                    a[j]=ans[i-1][j]+ans[i-1][j-1];
                }
            }
            ans[i]=a;
        }
        return ans;
    }
};