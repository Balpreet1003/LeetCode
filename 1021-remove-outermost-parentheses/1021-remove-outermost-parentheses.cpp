class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<pair<char,int>>st;
        int i=0;
        for(char ch:s){
            if(ch=='(')i++;
            else i--;
            st.push({ch,i});
        }
        string ans="";
        while(st.size()>1){
            auto x=st.top();
            st.pop();
            auto y=st.top();
            if(!(x.second==0 || (x.second==1 && y.second==0))) ans=x.first+ans;
        }
        return ans;
    }
};