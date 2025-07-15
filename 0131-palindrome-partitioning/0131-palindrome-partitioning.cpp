class Solution {
    bool isPalindrome(string&s){
        int i=0,j=s.length()-1;
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;j--;
        }
        return true;
    }
    vector<vector<string>>ans;
    void solve(string&s,int i, vector<string>&temp){
        if(i>=s.length()){
            ans.push_back(temp);
            return;
        }
        string s1="";
        for(int j=i;j<s.length();j++){
            s1+=s[j];
            if(isPalindrome(s1)){
                temp.push_back(s1);
                solve(s,j+1,temp);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string>temp;
        solve(s,0,temp);
        return ans;
    }
};