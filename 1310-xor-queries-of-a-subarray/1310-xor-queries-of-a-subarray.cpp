class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& q) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        vector<int>ans(q.size());
        for(int i=1;i<arr.size();i++){
            arr[i]^=arr[i-1];           
        }
        int x=0;
        for(auto i:q){
            int s=i[0],e=i[1];
            ans[x++]=(s>0?arr[e]^arr[s-1] : arr[e]);
        }
        return ans;
    }
};