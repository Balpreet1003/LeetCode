class Solution {
public:
    int possibleStringCount(string s) {
        int ans=1;
        char c=s[0];
        int x=1;
        for(auto i=1;i<s.length();i++){
            if(c==s[i])x++;
            else{
                ans+=(x-1);
                x=1;c=s[i];
            }
        }
        ans+=(x-1);
        return ans;
    }
};