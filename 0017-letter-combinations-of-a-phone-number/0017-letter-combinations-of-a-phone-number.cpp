class Solution {
    unordered_map<char,vector<char>>m;
    vector<string>ans;
    void solve(string&s, int i, string s1){
        if(i>=s.length()){
            ans.push_back(s1);
            return;
        }
        for(char ch:m[s[i]]){
            solve(s,i+1,s1+ch);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits=="")return {};
        m['2']={'a','b','c'};
        m['3']={'d','e','f'};
        m['4']={'g','h','i'};
        m['5']={'j','k','l'};
        m['6']={'m','n','o'};
        m['7']={'p','q','r','s'};
        m['8']={'t','u','v'};
        m['9']={'w','x','y','z'};
        solve(digits,0,"");

        return ans;
    }
};