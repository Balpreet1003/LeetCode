class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size(),m=queries.size();
        vector<int>a(n+1,0);
        for(int i=0;i<m;i++){
            a[queries[i][0]]+=1;
            a[queries[i][1]+1]-=1;
        }
        for(int i=1;i<n;i++){
            a[i]+=a[i-1];
        }
        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
            if(nums[i]>a[i])return false;
        }
        return true;
    }
};