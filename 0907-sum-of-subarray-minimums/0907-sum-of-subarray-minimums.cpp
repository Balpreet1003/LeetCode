class Solution {
    const int MOD = 1e9 + 7;
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        long long ans=0;
        vector<int>prev(n,-1),next(n,-1);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            prev[i] = (st.empty()) ? -1 : st.top();
            st.push(i);
        }
        while(!st.empty())st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            next[i] = (st.empty()) ? n : st.top();
            st.push(i);
        }
        for(int i=0;i<n;i++){
            long long l1=i-prev[i];
            long long l2=next[i]-i;
            ans=(ans+(((l1*l2)%MOD)*arr[i])%MOD)%MOD;
        }
        return ans;
    }
};