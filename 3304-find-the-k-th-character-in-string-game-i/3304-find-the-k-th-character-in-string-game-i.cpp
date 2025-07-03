class Solution {
public:
    char kthCharacter(int k) {
        string s="a";
        while(s.length()<=k){
            string s1="";
            for(char c:s){
                int x=c-'a'+1;
                s1+=('a'+x%26);
            }
            s+=s1;
        }
        return s[k-1];
    }
};