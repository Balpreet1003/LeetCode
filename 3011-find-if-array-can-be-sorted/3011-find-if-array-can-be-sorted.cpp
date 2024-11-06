class Solution {
    int numberOfSetbits(int n){
        int ans=0;
        while(n){
            n=n&(n-1);
            ans++;
        }
        return ans;
    }
public:
    bool canSortArray(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=1;j<n;j++){
                if(nums[j]<nums[j-1]){
                    int x=numberOfSetbits(nums[j]);
                    int y=numberOfSetbits(nums[j-1]);
                    if(x!=y)return false;
                    swap(nums[j],nums[j-1]);
                }
            }
        }
        return true;
    }
};