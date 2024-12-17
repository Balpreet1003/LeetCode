class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        unordered_map<char,int>m;
        priority_queue<pair<char,int>>pq;
        for(char ch:s){
            m[ch]++;
        }
        for(auto i:m)pq.push(i);
        string ans;
        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();
            int cnt=min(repeatLimit,curr.second);
            curr.second-=cnt;
            ans.append(cnt,curr.first);
            if(curr.second>0){
                if(pq.empty())break;
                auto next=pq.top();
                pq.pop();
                ans.append(1,next.first);
                next.second--;
                if(next.second>0)pq.push(next);
                pq.push(curr);
            }
        }
        return ans;
    }
};