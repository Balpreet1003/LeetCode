class Solution {
public:
    string concatHex36(int n) {
        string s1="",s2="";
        int n1=n*n;
        int n2=n*n*n;
        while(n1){
            int x=n1%16;
            if(x>9){
                x-=10;
                s1+=('A'+x);
            }
            else{
                s1+=to_string(x);
            }
            n1/=16;
        }
        reverse(s1.begin(),s1.end());
        while(n2){
            int x=n2%36;
            if(x>9){
                x-=10;
                s2+=('A'+x);
            }
            else{
                s2+=to_string(x);
            }
            n2/=36;
        }
        reverse(s2.begin(),s2.end());
        return s1+s2;
    }
};