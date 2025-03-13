class Solution {
    bool isPossible(vector<int>& nums, vector<vector<int>>& queries,int k){
        int n=nums.size(),m=queries.size();
        vector<int>a(n+1,0);
        for(int i=0;i<k;i++){
            a[queries[i][0]]+=queries[i][2];
            a[queries[i][1]+1]-=queries[i][2];
        }
        for(int i=1;i<n;i++){
            a[i]+=a[i-1];
        }
        for(int i=0;i<n;i++){
            if(nums[i]>a[i])return false;
        }
        return true;
    }
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int ans=-1;
        int i=0,j=queries.size();
        while(i<=j){
            int mid=(i+j)/2;
            if(isPossible(nums,queries,mid)){
                ans=mid;
                j=mid-1;
            }
            else i=mid+1;
        }
        return ans;
    }
};