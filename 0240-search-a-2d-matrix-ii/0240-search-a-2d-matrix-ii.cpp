class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int t) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int n=a.size();
        for(int i=0;i<n;i++){
            int j=0,k=a[i].size()-1;
            while(j<=k){
                int mid=(j+k)/2;
                if(a[i][mid]==t)return 1;
                if(a[i][mid]>t)k=mid-1;
                else j=mid+1;
            }
        }
        return 0;
    }
};