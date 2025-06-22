class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string>ans;
        string s1="";
        for(char c:s){
            if(s1.length()==k){
                ans.push_back(s1);
                s1="";
                s1+=c;
            }
            else{
                s1 += c;
            }
        }
        while(s1.length()<k){
            s1 += fill;
        }
        ans.push_back(s1);
        return ans;
    }
};