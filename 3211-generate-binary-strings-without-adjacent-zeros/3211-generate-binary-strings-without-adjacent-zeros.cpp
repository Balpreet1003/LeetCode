class Solution {
    set<string>ans;
    void solve(int n, string& s, bool val){
        if(n<=0){
            ans.insert(s);
            return;
        }
        s+=to_string(val);
        if(val){
            solve(n-1, s, val);
        }
        solve(n-1, s, !val);
        s.pop_back();
    }
public:
    vector<string> validStrings(int n) {
        string s="";
        solve(n, s, 0);
        solve(n, s, 1);
        return vector<string>(ans.begin(), ans.end());
    }
};