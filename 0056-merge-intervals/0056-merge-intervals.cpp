class Solution {
    static bool cmd(vector<int>&a,vector<int>&b){
        return a[0]<b[0];
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        vector<vector<int>>ans;
        sort(a.begin(),a.end(),cmd);
        int  x=a[0][0],y=a[0][1];
        for(int i=1;i<a.size();i++){
            if(a[i][0]<=y){
                y=max(y,a[i][1]);
            }
            else{
                ans.push_back({x,y});
                x=a[i][0];
                y=a[i][1];
            }
        }
        ans.push_back({x,y});
        return ans;
    }
};