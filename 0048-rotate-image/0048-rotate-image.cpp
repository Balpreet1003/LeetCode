class Solution {
    void reverse(vector<int>&nums){
        int i=0,j=nums.size()-1;
        while(i<j)swap(nums[i++],nums[j--]);
    }
public:
    void rotate(vector<vector<int>>& nums) {
        int n=nums.size();
        int x=0;
        for(int i=x;i<n;i++){
            for(int j=x+1;j<n;j++){
                swap(nums[i][j],nums[j][i]);
            }x++;
        }
        for(int i=0;i<n;i++){
            reverse(nums[i]);
        }
    }
};