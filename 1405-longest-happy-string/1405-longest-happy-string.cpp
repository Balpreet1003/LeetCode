class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);

        string ans="";
        priority_queue<pair<int,char>>pq;
        if(a!=0)pq.push({a,'a'});
        if(b!=0)pq.push({b,'b'});
        if(c!=0)pq.push({c,'c'});
        while(!pq.empty()){
            auto x=pq.top();
            pq.pop();
            if(ans.size()>=2 && ans[ans.size()-1]==x.second && ans[ans.size()-2]==x.second){
                if(!pq.empty()){
                    auto y=pq.top();
                    pq.pop();
                    ans+=y.second;
                    y.first--;
                    if(y.first!=0)pq.push(y);
                }
                else break;
            }
            else{
                ans+=x.second;
                x.first--;
            }
            if(x.first!=0)pq.push(x);
        }
        return ans;
    }
};