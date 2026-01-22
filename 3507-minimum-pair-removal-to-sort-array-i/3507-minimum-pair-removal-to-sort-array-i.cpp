class Solution {
    bool is_increasing(vector<int>& nums){
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1])return false;
        }
        return true;
    }
public:
    int minimumPairRemoval(vector<int>& nums) {
        int cnt=0;
        while(true){
            if(is_increasing(nums))break;
            vector<int>arr;
            int x=1;
            for(int i=1;i<nums.size();i++){
                if((nums[i]+nums[i-1])<(nums[x]+nums[x-1])){
                    x=i;
                }
            }
            for(int i=0;i<nums.size();i++){
                if(i==(x-1)) continue;
                else if(i==x) arr.push_back(nums[i]+nums[i-1]);
                else arr.push_back(nums[i]);
            }
            nums=arr;
            cnt++;
        }
        return cnt;
    }
};