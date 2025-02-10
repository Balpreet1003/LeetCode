class Solution {
public:
    string clearDigits(string s) {
        string ans="";
        stack<char>st;
        for(char ch:s){
            if(ch>='a' &&ch<='z'){
                st.push(ch);
            }
            else{
                if(!st.empty()){
                    st.pop();
                }
            }
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};