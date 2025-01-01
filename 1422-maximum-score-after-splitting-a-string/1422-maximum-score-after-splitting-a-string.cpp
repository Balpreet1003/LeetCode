class Solution {
public:
    int maxScore(string s) {
        int ans=0,cnt1=0,cnt0=0;
        for(char c:s){
            if(c=='1')cnt1++;
        }
        for(int i=0;i<s.length();i++){
            if(s[i]=='0')cnt0++;
            if(s[i]=='1')cnt1--;
            if(i!=s.length()-1)ans=max(ans,cnt1+cnt0);
        }
        return ans;
    }
};