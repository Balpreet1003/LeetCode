class Solution {
    bool isVowel(char& c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U')
            return true;
        return false; 
    }
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_map<string, vector<int>>m1;
        unordered_map<string, int>m2;
        for(int i=0;i<wordlist.size();i++){
            string s=wordlist[i];
            m2[s]=i;
            transform(s.begin(), s.end(), s.begin(), ::tolower);
            m1[s].push_back(i);
        }
        vector<string>ans;
        for(string s:queries){
            string s1=s;
            transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
            if(m2.count(s)){
                ans.push_back(s);
            }
            else if(m1.count(s1)){
                ans.push_back(wordlist[m1[s1][0]]);
            }
            else{
                bool flag=false;
                for(int i=0;i<wordlist.size();i++){
                    if(s1.length()==wordlist[i].length()){
                        string s2=wordlist[i];
                        transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
                        bool flag1=true;
                        for(int j=0;j<s1.length();j++){
                            if(s1[j]!=s2[j]){
                                if(!isVowel(s1[j]) || !isVowel(s2[j])){
                                    flag1=false;
                                    break;
                                }
                            }
                        }
                        if(flag1){
                            ans.push_back(wordlist[i]);
                            flag=true;
                            break;
                        }
                    }
                }
                if(!flag){
                    ans.push_back("");
                }
            }
        }
        return ans;
    }
};