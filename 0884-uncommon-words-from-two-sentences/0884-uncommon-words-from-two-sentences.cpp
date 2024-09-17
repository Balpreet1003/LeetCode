class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string>ans;
        unordered_map<string,int>m;
        string s=s1+" "+s2,temp="";
        for(char c:s){
            if(c==' '){
                m[temp]++;
                temp="";
            }
            else temp+=c;
        }
        if(temp!=""){
            m[temp]++;
            temp="";
        }

        for(auto i:m){
            if(i.second==1){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};