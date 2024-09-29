class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int >arrayOfs(26,0);
        for(char i:s){
            arrayOfs[i-'a']++;
        }
        vector<int >arrayOft(26,0);
        for(char i:t){
            arrayOft[i-'a']++;
        }
        for(int i=0;i<26;i++){
            if(arrayOfs[i]!=arrayOft[i]) return false;
        }
        return true;
    }
};