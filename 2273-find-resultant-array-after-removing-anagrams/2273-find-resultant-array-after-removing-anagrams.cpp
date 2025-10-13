class Solution {
    vector<int> get_cnt(string& s){
        vector<int>ans(26, 0);
        for(char c:s)
            ans[c-'a']++;
        return ans;
    }
public:
    vector<string> removeAnagrams(vector<string>& words) {
        stack<pair<int,vector<int>>>st;
        for(int i=0;i<words.size();i++){
            string s=words[i];
            vector<int>temp=get_cnt(s);
            if(st.empty() || st.top().second!=temp){
                st.push({i, temp});
            }
        }
        vector<string>ans;
        while(!st.empty()){
            ans.push_back(words[st.top().first]);
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};