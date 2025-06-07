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
        vector<bool>trace(n,true);

        for(int i=0;i<n;i++){
            if(s[i]=='*'){
                trace[i]=false;
                if(!pq.empty()){
                    trace[pq.top().second]=false;
                    pq.pop();
                }
            }
            else{
                pq.push({s[i],i});
            }
        }

        string ans="";
        for(int i=0;i<n;i++){
            if(trace[i])ans+=s[i];
        }
        return ans;
    }
};