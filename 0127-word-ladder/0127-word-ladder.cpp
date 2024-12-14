class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int>m;
        for(string s:wordList)m[s]=1;
        queue<string>q;
        q.push(beginWord);
        if(m.find(beginWord)!=m.end()){
            m.erase(beginWord);
        }
        int ans=0;
        while(!q.empty()){
            int len=q.size();
            ans++;
            while(len--){
                string s=q.front();
                q.pop();
                for(int i=0;i<s.length();i++){
                    string s1=s;
                    for(int j=0;j<26;j++){
                        s1[i]=char((int)('a')+j);
                        if(m.find(s1)!=m.end()){
                            if(s1==endWord)return ans+1;
                            q.push(s1);
                            m.erase(s1);
                        }
                    }
                }
            }
        }
        return 0;
    }
};