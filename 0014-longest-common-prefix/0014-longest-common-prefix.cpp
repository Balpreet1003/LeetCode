class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int min_len=INT_MAX;
        for(auto x:strs){
            min_len=min(min_len, (int)x.length());
        }
        string ans="";
        for(int i=0;i<min_len;i++){
            char ch=strs[0][i];
            bool flag=true;
            for(int j=1;j<strs.size();j++){
                if(ch!=strs[j][i]){
                    flag=false;
                    break;
                }
            }
            if(flag)
                ans+=ch;
            else
                break;
        }
        return ans;
    }
};