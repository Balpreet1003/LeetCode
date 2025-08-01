class Solution {
    bool is_possible(vector<int>&nums, int days, int sum){
        int sum1=0, cnt=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>sum){
                return false;
            }
            else if(sum1+nums[i]>sum){
                cnt++;
                sum1=nums[i];
            }
            else{
                sum1+=nums[i];
            }
        }
        return cnt<=days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int i=0, j=accumulate(weights.begin(), weights.end(),0);
        int ans=0;

        while(i<=j){
            int mid=(i+j)/2;
            if(is_possible(weights, days, mid)){
                ans=mid;
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        return ans;
    }
};