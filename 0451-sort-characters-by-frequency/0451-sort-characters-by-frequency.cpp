class Solution {
    struct cmd {
        bool operator()(pair<char, int>& a, pair<char, int>& b) {
            return a.second < b.second;
        }
    };
public:
    string frequencySort(string s) {
        unordered_map<char,int>m;
        for(char c:s)m[c]++;
        priority_queue<pair<char,int>,vector<pair<char,int>>,cmd>pq;
        for(auto i:m)pq.push(i);
        string ans="";
        while(!pq.empty()){
            int n=pq.top().second;
            char c=pq.top().first;
            pq.pop();
            while(n--)ans+=c;
        }
        return ans;
    }
};