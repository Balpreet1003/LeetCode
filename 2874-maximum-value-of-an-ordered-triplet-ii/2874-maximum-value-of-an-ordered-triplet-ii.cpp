class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        vector<int>left,right;
        int maxi=0;
        for(int i=n-1;i>=0;i--){
            right.push_back(maxi);
            maxi=max(maxi,nums[i]);
        }
        int i=0,j=n-1;
        while(i<j){
            swap(right[i++],right[j--]);
        }
        maxi=nums[0];
        long long ans=0;
        for(int i=1;i<n-1;i++){
            ans=max(ans,(long long)(maxi-nums[i])*right[i]);
            maxi=max(maxi,nums[i]);
        }
        return ans;
    }
};