class Solution {
    vector<vector<int>>ans;
    void solve(int&k,int&n,int i,int sum,vector<int>&a){
        if(a.size()==k && sum==n){
            ans.push_back(a);
            return;
        }
        if(i>9 || a.size()>=k)return;

        a.push_back(i);
        solve(k,n,i+1,sum+i,a);
        a.pop_back();
        solve(k,n,i+1,sum,a);
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        vector<int>a;
        solve(k,n,1,0,a);
        return ans;
    }
};