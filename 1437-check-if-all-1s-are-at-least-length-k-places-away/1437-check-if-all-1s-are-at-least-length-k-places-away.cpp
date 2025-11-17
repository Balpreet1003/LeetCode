class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int x=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                if(x!=-1 && (i-x-1)<k) 
                    return false;
                x=i;
            }
        }
        return true;
    }
};