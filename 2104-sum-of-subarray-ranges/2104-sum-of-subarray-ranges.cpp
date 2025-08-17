class Solution {
    long long get_max_sum(vector<int>& nums){
        int n=nums.size();
        stack<int>st;
        vector<int>prev(n,-1),next(n,-1);
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]<nums[i]){
                st.pop();
            }
            prev[i]=st.empty() ? -1 : st.top();
            st.push(i);
        }
        while(!st.empty())st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<=nums[i]){
                st.pop();
            }
            next[i]=st.empty() ? n : st.top();
            st.push(i); 
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            long long x=i-prev[i];
            long long y=next[i]-i;
            ans+=x*y*nums[i];
        }
        return ans;
    }
    long long get_min_sum(vector<int>& nums){
        int n=nums.size();
        stack<int>st;
        vector<int>prev(n,-1),next(n,-1);
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>nums[i]){
                st.pop();
            }
            prev[i]=st.empty() ? -1 : st.top();
            st.push(i);
        }
        while(!st.empty())st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }
            next[i]=st.empty() ? n : st.top();
            st.push(i); 
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            long long x=i-prev[i];
            long long y=next[i]-i;
            ans+=x*y*nums[i];
        }
        return ans;
    }
public:
    long long subArrayRanges(vector<int>& nums) {
        long long max_sum=get_max_sum(nums);
        long long min_sum=get_min_sum(nums);

        return max_sum-min_sum;
    }
};