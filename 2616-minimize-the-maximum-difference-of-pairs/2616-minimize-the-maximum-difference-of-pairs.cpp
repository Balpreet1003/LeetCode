class Solution {
    int is_possible(vector<int>&nums,int tar){
        int cnt=0,i=0;
        while(i<nums.size()-1){
            if(nums[i+1]-nums[i]<=tar){
                cnt++;
                i++;
            }
            i++;
        }
        return cnt;
    }
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());

        int i=0,j=nums[nums.size()-1]-nums[0];
        int ans=0;
        while(i<j){
            int mid=i+((j-i)/2);
            if(is_possible(nums,mid)>=p){
                j=mid;
            }
            else{
                i=mid+1;
            }
        }
        return i;
    }
};