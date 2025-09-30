class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return nums[0];
        vector<int>arr1=nums;
        for(int i=1;i<n;i++){
            vector<int>arr;
            for(int j=1;j<arr1.size();j++){
                arr.push_back((arr1[j-1]+arr1[j])%10);
            }
            arr1=arr;
        }
        return arr1[0];
    }
};