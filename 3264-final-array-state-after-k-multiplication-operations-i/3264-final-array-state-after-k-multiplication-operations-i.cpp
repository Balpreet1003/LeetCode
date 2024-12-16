class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int m) {
        int n=nums.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
        }
        while(k--){
            auto x=pq.top();
            pq.pop();
            x.first*=m;
            pq.push(x);
        }
        vector<int>ans(n);
        while(!pq.empty()){
            auto x=pq.top();
            pq.pop();
            ans[x.second]=x.first;
        }
        return ans;
    }
};