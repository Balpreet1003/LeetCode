class Solution {
public:
    string largestGoodInteger(string num) {
        string s="", ans="-1";
        for(auto x:num){
            if(s=="" || s[0]==x){
                if(s.length()==3){
                    s="";
                }
                s+=x;
            }
            else{
                s="";
                s+=x;
            }
            if(s.length()==3 && stoi(s)>stoi(ans)){
                ans=s;
            }
            cout<<s<<endl;
        }
        return ans=="-1" ? "" : ans;
    }
};