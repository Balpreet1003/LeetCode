class Solution {
public:
    bool canMakeSubsequence(string s, string s1) {
        int j=0;
        for(int i=0;i<s.length() && j<s1.length();i++){
            int x=(s[i]=='z')?-1:s[i]-'a';
            int y=s1[j]-'a';
            if((s[i]==s1[j]) || (y-x==1))j++;
        }
        return j==s1.length()?true:false;
    }
};