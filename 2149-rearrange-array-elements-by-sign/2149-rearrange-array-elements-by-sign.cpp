class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> pos;
        vector<int> neg;
        for(int i=0;i<n;i++){
            if(nums[i]<0)
                neg.push_back(nums[i]);
            else
                pos.push_back(nums[i]);
        }int j=0, i=0;
        while(i<n){
            nums[i++]=pos[j];
            nums[i++]=neg[j];
            j++;
        }
        return nums;
    }
};