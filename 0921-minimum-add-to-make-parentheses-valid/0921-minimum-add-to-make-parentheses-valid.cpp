class Solution {
public:
    int minAddToMakeValid(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int ans=0;
        stack<char>st;
        for(char c:s){
            if(c=='('){
                st.push(c);
            }
            else{
                if(!st.empty() && st.top()=='(')st.pop();
                else ans++;
            }
        }
        return ans+st.size();
    }
};