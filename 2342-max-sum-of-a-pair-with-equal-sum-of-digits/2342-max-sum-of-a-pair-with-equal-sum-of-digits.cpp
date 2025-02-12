class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int,priority_queue<int>>m;
        for(int i:nums){
            int x=i;
            int sum=0;
            while(x){
                sum+=(x%10);
                x/=10;
            }
            m[sum].push(i);
        }
        int ans=-1;
        for(auto &[i,j]:m){
            if(j.size()>1){
                int x=j.top();
                j.pop();
                ans=max(ans,x+j.top());
            }
        }
        return ans;
    }
};