class Solution {
    string ans="";
    int cnt;
    string s="";
    vector<char>arr={'a', 'b', 'c'};
    void solve(int& n, int& k){
        if(s.length()==n){
            cnt++;
            if(cnt==k)
                ans=s;
            return ;
        }
        if(s==""){
            for(int i=0;i<3;i++){
                s+=arr[i];
                solve(n, k);
                s.pop_back();
            }
        }
        else{
            for(int i=0;i<3;i++){
                //cout<<cnt<<" -> "<<s.length()-1<<endl;
                if(s[s.length()-1]!=arr[i]){
                    s+=arr[i];
                    solve(n, k);
                    s.pop_back();
                }
            }
        }
    }
public:
    string getHappyString(int n, int k) {
        if(k>(3*(1<<(n-1))))
            return "";
        solve(n, k);
        return ans;
    }
};