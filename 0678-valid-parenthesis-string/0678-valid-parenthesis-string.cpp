class Solution {
public:
    bool checkValidString(string s) {
        stack<char>st;
        for(char c:s){
            if(c=='('){
                st.push('(');
            }
            else if(c==')'){
                if(!st.empty() && st.top()=='(')st.pop();
            }
        }
        return st.empty();
    }
};