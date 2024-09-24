class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int n=s1.length(),m=s2.length();
        vector<int>prev(m+1,0),curr(m+1,0);
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int a1=0,a2=0,a3=0;
                if(s1[i]==s2[j]){
                    a1=prev[j+1]+1;
                }
                else{
                    a2=curr[j+1];
                    a3=prev[j];
                }
                curr[j]=max(a1,max(a2,a3));
            }
            prev=curr;
        }
        return curr[0];
    }
};