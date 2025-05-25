class Solution {
public:
    string resultingString(string s) {
        stack<char>st;
        for(char ch:s){
            if(st.size()<1)st.push(ch);
            else{
                if((abs(st.top()-ch)==1) || (abs(st.top()-ch)==25)){
                    st.pop();
                }
                else{
                    st.push(ch);
                }
            }
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};