class Solution { 
public: 
    string answerString(string s, int x) { 
        int n = s.size(); 
        if(x ==1) return s; 
        char c='a';
        for(char ch:s){
            if(ch>c)c=ch;
        }
        string ans = ""; 
        for(int i=0; i<n; i++) { 
            if(s[i] == c){ 
                int y = min((int)(n - i), n - x +1); 
                if(y <=0) continue; 
                string s1 = s.substr(i, y); 
                if(s1 > ans){ 
                    ans = s1; 
                } 
            } 
        } 
        return ans; 
    } 
};
