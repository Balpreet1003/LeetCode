class Solution {
    vector<vector<int>>ans;
    vector<int>a;
    void solve(int&k,int n,int i){
        if(a.size()==k && n==0){
            ans.push_back(a);
            return;
        }
        if(i>9 || a.size()>=k)return;

        a.push_back(i);
        solve(k,n-i,i+1);
        a.pop_back();
        solve(k,n,i+1);
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        solve(k,n,1);
        return ans;
    }
};