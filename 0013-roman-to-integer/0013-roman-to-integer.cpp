class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>m;
        m['I']=1;
        m['V']=5;
        m['X']=10;
        m['L']=50;
        m['C']=100;
        m['D']=500;
        m['M']=1000;

        int ans=0;
        for(int i=0;i<s.length();i++){
            if(i>0 && s[i]=='V' && s[i-1]=='I')ans+=3;
            else if(i>0 && s[i]=='L' && s[i-1]=='X')ans+=30;
            else if(i>0 && s[i]=='D' && s[i-1]=='C')ans+=300;
            else if(i>0 && s[i]=='X' && s[i-1]=='I')ans+=8;
            else if(i>0 && s[i]=='C' && s[i-1]=='X')ans+=80;
            else if(i>0 && s[i]=='M' && s[i-1]=='C')ans+=800;
            else ans+=m[s[i]];
        }
        return ans;
    }
};