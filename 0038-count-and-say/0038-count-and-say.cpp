class Solution {
    void rle(string& s){
        string ans="";
        int cnt=1;
        char ch =s[0];
        for(int i=1;i<s.length();i++){
            if(ch==s[i])cnt++;
            else{
                ans+=(to_string(cnt)+ch);
                cnt=1;
                ch=s[i];
            }
        }
        ans+=(to_string(cnt)+ch);
        s=ans;
    }
public:
    string countAndSay(int n) {
        if(n==1)return "1";
        string s="1";
        for(int i=1;i<n;i++){
            rle(s);
        }
        return s;
    }
};