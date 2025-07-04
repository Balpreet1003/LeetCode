class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.length()<=k){
            return "0";
        }
        string s="";
        stack<char>st;
        for(char c:num){
            while(!st.empty() && k>0 && c<st.top()){
                st.pop();
                k--;
            }
            st.push(c);
        }
        while(!st.empty() && k>0){
            st.pop();
            k--;
        }
        while(!st.empty()){
            s.push_back(st.top());
            st.pop();
        }
        reverse(s.begin(), s.end());

        int i=0;
        while(i<s.length() && s[i]=='0'){
            i++;
        }
        return i==s.length() ? "0" : s.substr(i);
    }
};