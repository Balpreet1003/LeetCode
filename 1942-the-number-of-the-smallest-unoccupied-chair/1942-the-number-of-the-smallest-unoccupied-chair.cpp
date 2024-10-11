class Solution {
public:
    int smallestChair(vector<vector<int>>& a, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        unordered_map<int,int>m;
        priority_queue<int,vector<int>,greater<int>>pq;
        vector<pair<int,int>>b;
        int n=a.size();
        for(int i=0;i<n;i++){
            b.push_back({a[i][0],i});
            b.push_back({a[i][1],~i});
        }
        sort(b.begin(),b.end());
        for(int i=n-1;i>=0;i--)pq.push(i);
        for(auto i:b){
            int t=i.first;
            int p=i.second;
            if(p>=0){
                if(p==k)return pq.top();
                m[p]=pq.top();
                pq.pop();
            }
            else{
                p=~p;
                pq.push(m[p]);
                m.erase(m.find(p));
            }
        }
        return -1;
    }
};