class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.length(),i=0,ans=0;
        vector<int>m(3,0);
        for(int j=0;j<n;j++){
            m[s[j]-'a']++;
            while(m[0]>0 && m[1]>0 &&m[2]>0){
                ans+=(n-j);
                m[s[i]-'a']--;
                i++;
            }
        }
        return ans;
    }
};