class Solution {
    static bool cmd(string&s1,string&s2){
        return s1.length()<s2.length();
    }
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        int n=folder.size();
        vector<bool>trace(n,true);
        sort(folder.begin(),folder.end(),cmd);
        vector<string>ans;
        unordered_map<string,int>m;
        for(int j=0;j<n;j++){
            string s=folder[j];
            string s1="";
            for(int i=0;i<s.length();){
                s1+=s[i++];
                while(i<s.length() && s[i]!='/'){
                    s1+=s[i++];
                }
                if(m.find(s1)!=m.end()){
                    trace[j]=false;
                    break;
                }
            }
            m[s]=1;
            if(trace[j]){
                ans.push_back(s);
            }
        }
        return ans;
    }
};