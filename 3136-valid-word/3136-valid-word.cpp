class Solution {
    bool isVowel(char& c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U'){
            return true;
        }
        return false;
    }
public:
    bool isValid(string word) {
        if(word.length()<3){
            return false;
        }
        int cnt1=0,cnt2=0;
        for(char c:word){
            if(isalpha(c)){
                if(isVowel(c)){
                    cnt1++;
                }
                else{
                    cnt2++;
                }
            }
            else if(isdigit(c)){}
            else{
                return false;
            }
        }
        if(cnt1>0 && cnt2>0){
            return true;
        }
        return false;
    }
};