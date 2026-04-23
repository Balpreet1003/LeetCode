class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(char ch:s)
        {
            if(ch=='c')
            {
                if(st.size()>1)
                {
                    char c1=st.top(); st.pop();
                    char c2=st.top(); st.pop();
                    if(!(c1=='b' && c2=='a'))
                        return false;
                }
                else
                    return false;
            }
            else
                st.push(ch);
        }
        return st.empty();
    }
};