class Solution {
    vector<int>next_smallest_ele(vector<int>&nums,int& n){
        stack<int>st;
        st.push(-1);
        vector<int>ans(n);
        for(int i=n-1;i>=0;i--){
            while(st.top()!=-1 && nums[st.top()]>=nums[i]){
                st.pop();
            }
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int>prev_smallest_ele(vector<int>&nums,int& n){
        stack<int>st;
        st.push(-1);
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            while(st.top()!=-1 && nums[st.top()]>=nums[i]){
                st.pop();
            }
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>next(n),prev(n);
        next=next_smallest_ele(heights,n);
        prev=prev_smallest_ele(heights,n);

        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            int l=heights[i];
            if(next[i]==-1){
                next[i]=n;
            }
            int b=next[i]-prev[i]-1;
            ans=max(ans,l*b);
        }   
        return ans;
    }
};