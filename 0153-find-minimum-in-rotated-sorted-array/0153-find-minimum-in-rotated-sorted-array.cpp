class Solution {
public:
    int findMin(vector<int>& nums) {
        int i=0,j=nums.size()-1,ans=0;
        while(i<=j){
            int mid=(i+j)/2;
            if(nums[mid]<nums[ans]){
                ans=mid;
            }

            if(nums[i]<nums[mid]){
                if(nums[i]<nums[j]){
                    j=mid-1;
                }
                else{
                    i=mid+1;
                }
            }
            else{
                j=mid-1;
            }
        }
        return nums[ans];
    }
};