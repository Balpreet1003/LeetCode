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
    int largest_rectangle_area(vector<int>& heights) {
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
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int>nums(matrix[0].size(),0);
        int ans=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<nums.size();j++){
                if(matrix[i][j]=='0')nums[j]=0;
                else nums[j]+=1;
            }

            ans=max(ans,largest_rectangle_area(nums));
        }
        return ans;
    }
};