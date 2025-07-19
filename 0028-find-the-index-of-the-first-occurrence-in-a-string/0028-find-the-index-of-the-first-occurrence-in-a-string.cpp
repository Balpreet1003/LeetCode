class Solution {
public:
    int strStr(string haystack, string needle) {
        int i=0,j=0;
        int ans=-1;
        while(i<haystack.length() && j<needle.length()){
            if(haystack[i]==needle[j]){
                if(ans==-1){
                    ans=i;
                }
                i++;j++;
            }
            else{
                j=0;
                i++;
                ans=-1;
            }
        }
        return j==needle.length() ? ans : -1;
    }
};