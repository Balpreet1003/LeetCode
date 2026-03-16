class Solution {
    char get_min(vector<int>& arr){
        for(int i=0;i<26;i++){
            if(arr[i])
                return 'a'+i;
        }
        return 'z';
    }
public:
    string robotWithString(string s) {
        vector<int>arr(26, 0);
        for(char c:s)
            arr[c-'a']++;
        stack<char>st;
        string ans="";
        for(char c:s){
            char mini=get_min(arr);
            while(!st.empty() && st.top()<=mini){
                ans+=st.top();
                st.pop();
            }
            st.push(c);
            arr[c-'a']--;
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};