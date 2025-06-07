class Solution {
    struct cmd {
        bool operator()(pair<char, int>& a, pair<char, int>& b) {
            if (a.first == b.first) return a.second < b.second;
            return a.first > b.first;
        }
    };
public:
    string clearStars(string s) {
        int n=s.length();
        priority_queue<pair<char,int>,vector<pair<char,int>>,cmd>pq;
        vector<bool>trace(n,false);

        for(int i=0;i<n;i++){
            if(s[i]=='*'){
                if(!pq.empty())pq.pop();
            }
            else{
                pq.push({s[i],i});
            }
        }

        while(!pq.empty()){
            trace[pq.top().second]=true;
            pq.pop();
        }

        string ans="";
        for(int i=0;i<n;i++){
            if(trace[i])ans+=s[i];
        }
        return ans;
    }
};