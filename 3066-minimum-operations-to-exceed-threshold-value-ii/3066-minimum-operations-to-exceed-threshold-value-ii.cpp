class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;
        int ans=0;
        for(int i:nums)pq.push(i);
        while(pq.size()>1 && pq.top()<k){
            int x=pq.top();
            pq.pop();
            int y=pq.top();
            pq.pop();
            pq.push((min(x,y)*2)+max(x,y));
            ans++;
        }
        return ans;
    }
};