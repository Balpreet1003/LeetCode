class Solution {
public:
    vector<vector<int>> generate(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        vector<vector<int>>ans={{1},{1,1}};
        if(n==1)return {{1}};
        if(n==2)return ans;

        for(int i=2;i<n;i++){
            vector<int>temp(i+1);
            temp[0]=1;temp[i]=1;
            for(int j=1;j<i;j++){
                temp[j]=ans[i-1][j-1]+ans[i-1][j];
            }
            ans.push_back(temp);
        }
        return ans;
    }
};