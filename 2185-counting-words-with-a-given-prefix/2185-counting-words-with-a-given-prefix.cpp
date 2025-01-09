class Solution {
    bool isPoss(string&p,string&s){
        for(int i=0;i<p.length();i++){
            if(p[i]!=s[i])return false;
        }
        return true;
    }
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans=0;
        for(string s:words){
            if(pref.length()<=s.length()){
                if(isPoss(pref,s))ans++;
            }
        }
        return ans;
    }
};