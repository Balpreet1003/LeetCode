class Solution {
    bool compare(string& s1, string s2){
        int i = 0, j = 0;
        while (i < s1.length() && s1[i] == '0') i++;
        while (j < s2.length() && s2[j] == '0') j++;

        string trimmedA = s1.substr(i);
        string trimmedB = s2.substr(j);

        if (trimmedA.length() > trimmedB.length()) return true; 
        if (trimmedA.length() < trimmedB.length()) return false;

        for (int k = 0; k < trimmedA.length(); k++) {
            if (trimmedA[k] > trimmedB[k]) return true;
            if (trimmedA[k] < trimmedB[k]) return false;
        }

        return true; 
    }
public:
    int longestSubsequence(string s, int k) {
        int n=s.length(),x=0;
        vector<int>a(n+1,0);
        for(int i=0;i<n;i++){
            a[i]=x;
            if(s[i]=='0')x++;
        }
        a[n]=x;
        string s1="";
        while(k){
            char c=(k&1)?'1':'0';
            s1+=c;
            k/=2;
        }
        reverse(s1.begin(),s1.end());
        int ans=a[n];
        for(int i=n-1;i>=0;i--){
            if(compare(s1,s.substr(i))){
                ans=max(ans,n-i+a[i]);
            }
            else{
                break;
            }
        }
        return ans;

    }
};