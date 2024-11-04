class Solution {
public:
    string compressedString(string s) {
        int x=1;
        char c=s[0];
        string ans="";
        for(int i=1;i<s.length();i++){
            if(s[i]==c)x++;
            else{
                while(x>0){
                    int y=min(9,x);
                    ans+=(to_string(y)+c);
                    x-=y;
                }
                x=1;
                c=s[i];
            }
        }
        while(x>0){
            int y=min(9,x);
            ans+=(to_string(y)+c);
            x-=y;
        }
        return ans;
    }
};