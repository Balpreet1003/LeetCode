class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int mis=-1, dup=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[abs(nums[i])-1]<0){
                dup=abs(nums[i]);
            }
            else{
                nums[abs(nums[i])-1]*=-1;
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                mis=i+1;
                break;
            }
        }
        return {dup, mis};
    }
};