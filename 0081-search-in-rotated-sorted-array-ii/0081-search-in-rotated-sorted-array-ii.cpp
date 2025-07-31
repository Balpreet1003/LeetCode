class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size()==1){
            return nums[0]==target ? true : false;
        }
        int i=0,j=nums.size()-1;
        while(i<=j){
            int mid=(i+j)/2;
            if(nums[mid]==target){
                return true;
            }
            if(nums[i]==nums[mid] && nums[mid]==nums[j]){
                i++;
                j--;
                continue;
            }
            else if(nums[mid]<nums[i]){
                if(nums[mid]<=target && nums[j]>=target){
                    i=mid+1;
                }
                else{
                    j=mid-1;
                }
            }
            else{
                if(nums[mid]>=target && nums[i]<=target){
                    j=mid-1;
                }
                else{
                    i=mid+1;
                }
            }
        }
        return false;
    }
};