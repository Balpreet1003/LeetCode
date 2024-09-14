class Solution {
public:
    int maxProduct(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int p=1,n=nums.size(),maxi=-11;
        for(int  i=0;i<n;i++){
            p*=nums[i];
            maxi=max(maxi,p);
            if(p==0)p=1;
        }
        p=1;
        for(int i=n-1;i>=0;i--){
            p*=nums[i];
            maxi=max(maxi,p);
            if(p==0)p=1;
        }
        return maxi;
    }
};