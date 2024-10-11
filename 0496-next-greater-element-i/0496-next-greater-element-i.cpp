class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size(),-1);
        stack<int> st;
        unordered_map<int,int> mp;
        for(int num:nums2){
            while(!st.empty() && st.top()<num){
                mp[st.top()]=num;
                st.pop();
            }
            st.push(num);
        }
        for(int i=0;i<nums1.size();i++){
            if(mp[nums1[i]]) ans[i]=mp[nums1[i]];
        }
        return ans;
    }
};