class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int t) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        
        int i=0,j=a[0].size()-1;
        while(i<a.size() && j>=0){
            if(a[i][j]==t)return 1;
            if(a[i][j]>t)j--;
            else i++;
        }
        return 0;
    }
};