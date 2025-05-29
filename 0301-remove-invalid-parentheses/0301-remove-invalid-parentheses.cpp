class Solution {
    set<string>ans;
    int k=0;
    void get_cnt(string&s) {
        stack<char>st;
        for(char c:s){
            if(c=='(') st.push(c);
            else if(c==')'){
                if(st.empty())k++;
                else if(st.top()=='(')st.pop();
            }
        }
        k+=st.size();
    }
    bool is_correct(string& s) {
        stack<char>st;
        for(char c:s){
            if(c=='(') st.push(c);
            else if(c==')'){
                if(st.empty())return false;
                if(st.top()=='(')st.pop();
            }
        }
        return st.empty();
    }
    void solve(string& s, string& s1, int i){
        if(i>=s.length()){
            if(is_correct(s1) && k==0)ans.insert(s1);
            return ;
        }

        if(s[i]!='(' && s[i]!=')') {
            s1.push_back(s[i]);
            solve(s,s1,i+1);
            s1.pop_back();
        }
        else {
            s1.push_back(s[i]);
            solve(s,s1,i+1);
            s1.pop_back();

            if(k>0){
                k--;
                solve(s,s1,i+1);
                k++;
            }
        }
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        string s1="";
        get_cnt(s);
        solve(s,s1,0);
        return vector<string>(ans.begin(),ans.end());
    }
};