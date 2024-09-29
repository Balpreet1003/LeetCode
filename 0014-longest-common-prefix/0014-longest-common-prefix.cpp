class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()<2)
            return strs[0];
        string ans="";
        int size1= strs[0].length()>strs[1].length() ? strs[1].length():strs[0].length();
        int i=0;
        while(i<size1){
            if(strs[0][i]==strs[1][i])
                ans+=strs[0][i];
            else
                break;
            i++;
        }
        
        for(int i=2;i<strs.size();i++){
            if(ans.length()==0)
                return "";
            string temp=ans;
            ans="";
            size1= temp.length()>strs[i].length()? strs[i].length():temp.length();
            for(int j=0;j<size1;j++){
                if(temp[j]==strs[i][j])
                    ans+=strs[0][j];
                else
                    break;
            }
        }
        return ans;
    }
};