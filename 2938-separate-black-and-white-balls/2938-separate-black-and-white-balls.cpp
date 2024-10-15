class Solution {
public:
    long long minimumSteps(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int i=0,n=s.length();
        long long ans=0;
        while(i<n && s[i]=='0')i++;
        for(int j=i+1;j<n;j++){
            if(s[j]=='0'){
                ans=ans+(long long)(j-i);
                i++;
            }
        }
        return ans;
    }
};