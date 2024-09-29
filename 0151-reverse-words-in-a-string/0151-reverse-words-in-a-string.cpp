class Solution {
public:
    string reverseWords(string s) {
        string s1="";
        string ans="";
        for(char ch:s){
            if(ch==' '){
                if(s1!="") ans=s1+" "+ans;
                s1="";
            }
            else s1+=ch;
        }
        if(s1!="") ans=s1+" "+ans;
        ans.pop_back();
        return ans;
    }
};