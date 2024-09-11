class Solution {
public:
    int searchInsert(vector<int>& nums, int t) {
        int i=0,j=nums.size()-1,ans=0;
        while(i<=j){
            int mid=(i+j)/2;
            if(nums[mid]==t)return mid;
            else if(nums[mid]<t){
                ans=mid+1;
                i=mid+1;
            }
            else{
                j=mid-1;
            }
        }
        return ans;
    }
};