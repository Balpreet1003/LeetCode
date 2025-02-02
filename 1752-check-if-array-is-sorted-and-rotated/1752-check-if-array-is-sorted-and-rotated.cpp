class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size(), i=1;
        for(;i<n;i++){
            if(nums[i]<nums[i-1])break;
        }
        int j=i+1;
        if(i==n){
            i=0;
            j=i+1;
        }
        while(j!=i){
            if(j==n){
                j=0;
                if(i==0)break;
                if(nums[n-1]>nums[0])return 0;
            }
            else{
                if(nums[j-1]>nums[j])return 0;
            }
            j++;
        }
        return 1;
    }
};
