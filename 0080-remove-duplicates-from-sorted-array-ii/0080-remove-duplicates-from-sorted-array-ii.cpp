class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=nums.size(),n=nums.size(),cnt=1,num=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]==num){
                cnt++;
                if(cnt>2){
                    k--;
                    nums[i]=INT_MIN;
                }
            }
            else{
                cnt=1;
                num=nums[i];
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]!=INT_MIN){
                int j=i-1;
                while(j>=0 && nums[j]==INT_MIN){
                    j--;
                }
                swap(nums[i],nums[j+1]);
            }
        }
        return k;
    }
};