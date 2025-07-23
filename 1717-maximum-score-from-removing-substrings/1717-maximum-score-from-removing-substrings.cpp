class Solution {
public:
    int maximumGain(string s, int z, int y) {
        string t="";
        stack<char>st;
        int ans=0;
        if(z>y)t="ab";
        else t="ba";
        for(auto x:s){
            if(!st.empty() && x==t[1] && st.top()==t[0]){
                ans+=max(z,y);
                st.pop();
            }
            else{
                st.push(x);
            }
        }
        if(t=="ab")t="ba";
        else t="ab";
        s="";
        while(!st.empty()){
            s+=st.top();
            st.pop();
        }
        reverse(s.begin(),s.end());
        for(auto x:s){
            if(!st.empty() && x==t[1] && st.top()==t[0]){
                ans+=min(z,y);
                st.pop();
            }
            else{
                st.push(x);
            }
        }
        return ans;
    }
};