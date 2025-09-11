class Solution {
    bool isVowel(char& c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U')
            return true;
        return false;
    }
public:
    string sortVowels(string s) {
        string s1="";
        for(char c:s){
            if(isVowel(c))
                s1+=c;
        }
        sort(s1.begin(), s1.end());
        int i=0;
        string ans=s;
        for(char &c:ans){
            if(isVowel(c))
                c=s1[i++];
        }
        return ans; 
    }
};