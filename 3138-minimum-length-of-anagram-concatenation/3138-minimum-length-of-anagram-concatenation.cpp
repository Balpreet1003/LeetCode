class Solution {
public:
    bool check(int k, string &s){
        map<char,int>mp1;
        for(int i=0;i<k;i++) mp1[s[i]]++;

        for(int i=k;i<s.size();i+=k){
            map<char,int>mp;
            for(int j=i;j<i+k;j++)mp[s[j]]++;
            if(mp!=mp1) return 0;
        }
        return 1;

    }
    int minAnagramLength(string s) {
        int n = s.size();
        for(int i=1;i<=s.size();i++){
            if(n%i==0 && check(i,s)) return i;
        }
        return n;
    }
};