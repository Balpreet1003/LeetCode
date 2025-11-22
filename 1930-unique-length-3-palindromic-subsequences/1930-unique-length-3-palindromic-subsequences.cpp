class Solution {
    int first_index(string& s, char& c){
        for(int i=0;i<s.length();i++){
            if(s[i]==c)
                return i;
        }
        return -1;
    }
    int last_index(string& s, char& c){
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]==c)
                return i;
        }
        return -1;
    }
    int get_unique(string& s, int l, int r){
        vector<int>cnt(26, 0);
        for(int i=l+1; i<r; i++){
            cnt[s[i]-'a']++;
        }
        int ans=0;
        for(int i:cnt){
            if(i>0)ans++;
        }
        return ans;
    }
public:
    int countPalindromicSubsequence(string s) {
        int ans=0;
        for(char c='a';c<='z';c++){
            int left=first_index(s, c);
            int right=last_index(s, c);
            if(left!=-1 && right!=-1 && right-left>1){
                ans += get_unique(s, left, right);
            }
        }
        return ans;
    }
};