class Solution {
public:
    string longestPalindrome(string s) {
        int x=0,n=s.size();
        string ans="";
        for(int i=0;i<n;i++){
            string s1="";
            for(int j=i;j<n;j++){
                s1+=s[j];
                int l=0,r=s1.length()-1;
                bool cond=true;
                while(l<r){
                    if(s1[l]!=s1[r]){
                        cond=false;
                        break;
                    }
                    l++;
                    r--;
                }
                if(cond && x<s1.length()){
                    x=s1.length();
                    ans=s1;
                }
            }
        }
        return ans;
    }
};