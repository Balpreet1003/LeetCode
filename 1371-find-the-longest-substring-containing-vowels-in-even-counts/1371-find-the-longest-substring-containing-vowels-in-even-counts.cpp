class Solution {
public:
    int findTheLongestSubstring(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        unordered_map<int,int>m;
        m[0]=-1;
        int mask=0;
        int len=0;
        vector<int>vow(5,0);
        for(int i=0;i<s.length();i++){
            if(s[i]=='a') mask=mask^(1<<0);
            else if(s[i]=='e') mask=mask^(1<<1);
            else if(s[i]=='i') mask=mask^(1<<2);
            else if(s[i]=='o') mask=mask^(1<<3);
            else if(s[i]=='u') mask=mask^(1<<4);

            if(m.find(mask)==m.end())m[mask]=i;
            else len=max(len,i-m[mask]);
        }
        return len;
    }
};