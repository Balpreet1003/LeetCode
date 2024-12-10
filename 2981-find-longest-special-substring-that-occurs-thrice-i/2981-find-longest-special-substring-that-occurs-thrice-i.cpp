class Solution {
public:
    int maximumLength(string s) {
        int ans=-1,n=s.length();
        unordered_map<string,int>m;
        for(int i=0;i<n;i++){
            string a="";
            for(int j=i;j<n;j++){
                if(s[i]==s[j]){
                    a+=s[j];
                    m[a]++;
                }
                else break;
            }
        }
        for( auto i:m){
            int x=(i.first).length();
            if(i.second>=3)ans=max(ans,x);
        }
        return ans;
    }
};