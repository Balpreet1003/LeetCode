class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>m;
        int n=nums2.size();
        stack<int>st;
        st.push(-1);
        for(int i=n-1;i>=0;i--){
            while(st.top()!=-1 && st.top()<=nums2[i]){
                st.pop();
            }
            m[nums2[i]]=st.top();
            st.push(nums2[i]);
        }
        vector<int>ans;
        for(int i:nums1){
            ans.push_back(m[i]);
        }
        return ans;
    }
};