class Solution {
    vector<string>ans;
    void solve(int& n,int i,int j,string s){
        if(i>n || j>n)return;
        if(i==n && j==n){
            ans.push_back(s);
            return;
        }
        solve(n,i+1,j,s+"(");
        if(i>j)solve(n,i,j+1,s+")");
    }
public:
    vector<string> generateParenthesis(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        solve(n,0,0,"");
        return ans;
    }
};