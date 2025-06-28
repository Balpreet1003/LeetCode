class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n=nums.size();
        vector<bool>a(n,false);
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
        }
        while(k-- && !pq.empty()){
            auto [x,y]=pq.top();
            pq.pop();
            a[y]=true;
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(a[i]){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};