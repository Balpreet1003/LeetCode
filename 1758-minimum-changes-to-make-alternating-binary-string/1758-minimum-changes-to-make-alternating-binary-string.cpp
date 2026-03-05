class Solution {
public:
    int minOperations(string s) {
        int ans1=0, ans2=0;
        string s1=s;
        if(s1[0]=='1')
            ans1++;
        s1[0]='0';
        for(int i=1;i<s.length();i++){
            if(s1[i]==s1[i-1]){
                s1[i]=s1[i-1]=='1'?'0':'1';
                ans1++;
            }
        }
        if(s[0]=='0')
            ans2++;
        s[0]='1';
        for(int i=1;i<s.length();i++){
            if(s[i]==s[i-1]){
                s[i]=s[i-1]=='1'?'0':'1';
                ans2++;
            }
        }
        return min(ans1, ans2);
    }
};