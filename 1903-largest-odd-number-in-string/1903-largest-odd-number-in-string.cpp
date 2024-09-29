class Solution {
public:
    string largestOddNumber(string s) {
        int i=s.length()-1;
        for(;i>=0;i--){
            if((s[i]-'0')&1)break;
        }
        return i<0?"":s.substr(0,i+1); 
    }
};