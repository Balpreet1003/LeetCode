class Solution {
    bool isPossible(vector<int>&nums,int k,int x){
        int cnt=0,n=nums.size();
        for(int i=0;i<n;){
            if(nums[i]<=x){
                cnt++;
                i+=2;
            }
            else{
                i++;
            }
        }
        return cnt>=k;
    }
public:
    int minCapability(vector<int>& nums, int k) {
        int ans=-1,i=INT_MAX,j=INT_MIN;
        for(int x:nums)i=min(i,x),j=max(j,x);

        while(i<=j){
            int mid=(i+j)/2;
            if(isPossible(nums,k,mid)){
                ans=mid;
                j=mid-1;
            }
            else i=mid+1;
        }
        return ans;
    }
};