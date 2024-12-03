class Solution {
public:
    string addSpaces(string s, vector<int>& a) {
        //brute force 
        // for(int i=0;i<a.size();i++){
        //     s= s.substr(0,a[i]+i)+" "+s.substr(a[i]+i,s.length()-(a[i]+i));
        // }
        // return s;

        //optimoise solution
        string ans="";
        int j=0;
        for(int i=0;i<s.length();i++){
            if(j<a.size() && i==a[j]){
                ans+=" ";
                j++;
            }
            ans+=s[i];
        }
        return ans;
    }
};