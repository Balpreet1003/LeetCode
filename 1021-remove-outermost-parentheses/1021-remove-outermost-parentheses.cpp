class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt = 0; 
        string ans="";
        
        for( char i : s){
            if( i == '('){
                if(cnt > 0){
                ans+=i;
                }
                cnt++;
            }
        else {
            cnt--;
            if(cnt > 0){
                ans += i;
            }
        }
        }
        return ans;
     }
};