class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int>m;
        int i=0,j=0,ans=0,n=s.length();
        while(j<n){
            if(m.size()>=3){
                ans+=(n-j+1);
                m[s[i]]--;
                if(m[s[i]]<=0)m.erase(s[i]);
                i++;
            }
            else{
                m[s[j]]++;
                j++;
            }
        }
        while(m.size()>=3){
            ans+=(n-j+1);
            m[s[i]]--;
            if(m[s[i]]<=0)m.erase(s[i]);
            i++;
        }
        return ans;
    }
};