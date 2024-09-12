class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);

        vector<int>m(26,0);
        for(char c:allowed)m[c-'a']++;
        int ans=0;
        for(string s:words){
            bool flag=1;
            for(char c:s){
                if(m[c-'a']==0){
                    flag=0;
                    break;
                }
            }
            if(flag)ans++;
        }
        return ans;
    }
};