class Solution {
public:
    int minSwaps(string s) {
        stack<int>st;
        for(char i:s){
            if(i=='[')st.push(i);
            else if(!st.empty() && st.top()=='[')st.pop();
        }
        int x=st.size();
        return (x+1)/2;
    }
};