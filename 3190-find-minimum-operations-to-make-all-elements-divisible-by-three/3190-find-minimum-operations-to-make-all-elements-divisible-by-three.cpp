class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans=0;
        for(int i:nums){
            ans+=(min(3-(i%3), i%3));
        }
        return ans;
    }
};