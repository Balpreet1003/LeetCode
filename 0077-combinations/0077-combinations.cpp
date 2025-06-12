class Solution {
    vector<int>temp;
    vector<vector<int>>ans;
    void solve(int& n, int& k, int i){
        if(i>n){
            if(temp.size()==k)ans.push_back(temp);
            return;
        }
        if(temp.size()>k)return ;

        solve(n,k,i+1);
        temp.push_back(i);
        solve(n,k,i+1);
        temp.pop_back();
    }
public:
    vector<vector<int>> combine(int n, int k) {
        solve(n,k,1);
        return ans;
    }
};