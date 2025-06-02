class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        unordered_map<string,int>word,visited;
        bool flag=false;
        for(string s:wordList){
            word[s]++;
            if(s==endWord)flag=true;
        }
        if(!flag)return 0;

        q.push({beginWord,1});
        visited[beginWord]=1;
        while(!q.empty()){
            auto [node,h]=q.front();
            q.pop();

            if(node==endWord)return h;

            for(int i=0;i<node.length();i++){
                char initial=node[i];
                for(int j=0;j<26;j++){
                    if(initial!=char('a'+j)){
                        node[i]=('a'+j);
                        if(visited.find(node)==visited.end() && word.find(node)!=word.end()){
                            q.push({node,h+1});
                            visited[node]=1;
                        }
                    }
                }
                node[i]=initial;
            }
        }
        return 0;
    }
};