class Solution {
    bool isVowel(char& c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='o')
            return true;
        return false;
    }
public:
    bool doesAliceWin(string s) {
        int cnt=0;
        for(char c:s){
            if(isVowel(c))cnt++;
        }
        return cnt!=0;
    }
};