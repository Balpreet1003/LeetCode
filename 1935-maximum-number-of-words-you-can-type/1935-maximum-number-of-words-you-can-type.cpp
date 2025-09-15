class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<int>m(26,0);
        for(char c:brokenLetters)
            m[c-'a']++;

        for(int i:m)cout<<i<<" ";
        int ans=0;
        for(int i=0;i<text.length();i++){
            bool flag=true;
            while(i<text.length() && text[i]!=' '){
                if(m[text[i]-'a']==0)
                    flag=false;
                i++;
            }
            if(flag)
                ans++;
        }
        return ans;
    }
};