class Solution {
    int findOr(int n){
        for(int i=0;i<=n;i++){
            if((i|(i+1))==n)return i;
        }
        return -1;
    }
public:
    vector<int> minBitwiseArray(vector<int>& a) {
        int n=a.size();
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            ans[i]=findOr(a[i]);
        }
        return ans;
    }
};