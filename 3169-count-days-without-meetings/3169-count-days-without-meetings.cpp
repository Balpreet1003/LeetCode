class Solution {
public:
    int countDays(int days, vector<vector<int>>& m) {
        sort(m.begin(),m.end());
        int start=m[0][0],end=m[0][1];
        for(int i=1;i<m.size();i++){
            if(end>=m[i][0]){
                end=max(end,m[i][1]);
            }
            else{
                days-=(end-start+1);
                start=m[i][0];
                end=m[i][1];
            }
        }
        days-=(end-start+1);
        return days;
    }
};