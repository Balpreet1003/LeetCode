class Solution {
    char dfs(unordered_map<char, vector<char>>& adj,vector<bool>&visited,char& c){
        char ans=c;
        visited[c-'a']=true;
        for(char ch:adj[c]){
            if(!visited[ch-'a']){
                ans=min(ans,dfs(adj,visited,ch));
            }
        }
        return ans;
    }
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        unordered_map<char, vector<char>>adj;
        int n=s1.length();
        for(int i=0;i<n;i++){
            adj[s1[i]].push_back(s2[i]);
            adj[s2[i]].push_back(s1[i]);
        }
        string ans=baseStr;
        for(int i=0;i<ans.length();i++){
            vector<bool>visited(26,false);
            char ch=dfs(adj,visited,ans[i]);
            ans[i]=ch;
        }
        return ans;
    }
};