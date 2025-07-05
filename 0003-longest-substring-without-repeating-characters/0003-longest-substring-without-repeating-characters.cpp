class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        unordered_map<char,int>m;
        int i=0,j=0,ans=1;
        for(int j=0;j<n;j++){
            while(m[s[j]]>=1) {
                m[s[i]]--;
                i++;
            }
            m[s[j]]++;
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};