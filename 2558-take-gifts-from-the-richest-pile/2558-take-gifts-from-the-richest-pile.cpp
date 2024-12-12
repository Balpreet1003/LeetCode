class Solution {
public:
    long long pickGifts(vector<int>& a, int k) {
        priority_queue<int>pq;
        for(int i:a){
            pq.push(i);
        }
        while(k--){
            int x=floor(sqrt(pq.top()));
            pq.pop();
            pq.push(x);
        }
        long long ans=0;
        while(!pq.empty()){
            ans+=(long long )(pq.top());
            pq.pop();
        }
        return ans;
    }
};