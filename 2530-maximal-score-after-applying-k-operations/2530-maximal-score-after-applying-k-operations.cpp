class Solution {
    long long Ceil(long long&x){
        if(x%3==0)return x/3;
        return (x/3)+1;
    }
public:
    long long maxKelements(vector<int>& a, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        long long ans=0;
        priority_queue<int>pq;
        for(int i:a)pq.push(i);
        while(k-- && !pq.empty()){
            long long x=(long long)pq.top();
            pq.pop();
            ans+=x;
            x=Ceil(x);
            pq.push(x);
        }
        return ans;
    }
};