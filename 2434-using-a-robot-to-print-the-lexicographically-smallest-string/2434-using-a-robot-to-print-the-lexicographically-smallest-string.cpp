class Solution {
    char find_min_char(vector<int>&freq){
        for(int i=0;i<26;i++){
            if(freq[i])return 'a'+i;
        }
        return 'z';
    }
public:
    string robotWithString(string s) {
        string ans="";
        stack<char>st;
        vector<int>freq(26,0);
        for(char ch:s)freq[ch-'a']++;

        for(char ch:s){
            char mini=find_min_char(freq);

            while(!st.empty() && st.top()<=mini){
                ans+=st.top();
                st.pop();
            }
            st.push(ch);
            freq[ch-'a']--;
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};