class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int ans=0,n=nums.size();
        vector<int>a(n);
        a[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            a[i]=max(a[i+1],nums[i]);
        }
        int i=0,j=0;
        while(j<n){
            while(j<n && a[j]>=nums[i])j++;
            ans=max(ans,j-i-1);
            i++;
            j=i+ans+1;
        }
        return ans;
    }
};