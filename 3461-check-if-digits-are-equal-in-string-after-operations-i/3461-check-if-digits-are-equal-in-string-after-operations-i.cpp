class Solution {
public:
    bool hasSameDigits(string s) {
        while(s.length()>2){
            string s1="";
            for(int i=1;i<s.length();i++){
                int sum=(s[i]-'0')+(s[i-1]-'0');
                sum%=10;
                s1+=to_string(sum);
            }
            s=s1;
            //cout<<s<<endl;
        }
        return s[0]==s[1];
    }
};