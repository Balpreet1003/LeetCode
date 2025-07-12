class Solution {
public:
    string countAndSay(int n) {
        string ans="1";
        for(int i=2;i<=n;i++){
            int cnt=1;
            string s="";
            for(int j=1;j<ans.length();j++){
                if(ans[j-1]==ans[j]){
                    cnt++;
                }
                else{
                    s+=to_string(cnt);
                    s+=ans[j-1];
                    cnt=1;
                }
            }
            s+=to_string(cnt);
            s+=ans[ans.length()-1];
            ans=s;
        }
        return ans;
    }
};