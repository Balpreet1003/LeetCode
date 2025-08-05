class Solution {
public:
    void sortColors(vector<int>& nums) {
       int redCount=0,whiteCount=0,blueCount=0;
       for(int i=0;i<nums.size();i++){
           if(nums[i]==0)redCount++;
           if(nums[i]==1)whiteCount++;
           if(nums[i]==2)blueCount++;
       }
       int k=0;
       while(redCount--){
           nums[k]=0;
           k++;
       }
       while(whiteCount--){
           nums[k]=1;
           k++;
       }
       while(blueCount--){
           nums[k]=2;
           k++;
       }
    }
};