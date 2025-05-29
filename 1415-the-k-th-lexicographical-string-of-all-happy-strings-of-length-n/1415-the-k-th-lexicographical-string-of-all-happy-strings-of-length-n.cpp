class Solution {
    vector<string>ans;
    string s="";
    void solve(int& n,int& k){
        if(s.length()>=n){
            ans.push_back(s);
            return;
        }
        if(ans.size()>=k)return ;

        for(int i=0;i<3;i++){
            char ch=char(i+'a');
            if(s!="" && s.back()==ch)continue;

            s.push_back(ch);
            solve(n,k);
            s.pop_back();
        }
    }
public:
    string getHappyString(int n, int k) {
        solve(n,k);
        if(ans.size()<k)return "";
        return ans[k-1];
    }
};