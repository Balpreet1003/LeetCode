class Solution {
    bool solve(string& s, int i, string s1){
        if(s1.length()>19)
            return false;
        if(i>=s.length()){
            return s1!="" && s!=s1;
        }
        string s2="";
        for(int j=i;j<s.length();j++){
            s2+=s[j];
            if(s2.length()>19)
                break;
            if(s1=="" || stold(s1)-stold(s2)==1){
                if(solve(s, j+1, s2))
                    return true;
            }
        }
        return false;
    }
public:
    bool splitString(string s) {
        return solve(s, 0, "");
    }
};