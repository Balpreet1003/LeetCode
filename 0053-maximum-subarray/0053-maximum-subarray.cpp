class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        std::ios::sync_with_stdio(NULL); 
        std::cin.tie(NULL);
        int sum=0,maxSum=INT_MIN;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            maxSum=max(maxSum,sum);
            if(sum<0) sum=0;
        }
        return maxSum;
    }
};