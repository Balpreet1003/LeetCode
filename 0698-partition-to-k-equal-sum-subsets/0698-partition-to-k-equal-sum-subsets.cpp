class Solution {
    bool is_correct(vector<int>&a){
        for(int i=1;i<a.size();i++){
            if(a[i]!=a[i-1])return false;
        }
        return true;
    }
    bool isPoss(vector<int>&nums,vector<int>&sum,int lim, int i){
        if(i>=nums.size()){
            return is_correct(sum);
        }

        for(int j=0;j<sum.size();j++){
            if(sum[j]+nums[i]<=lim){
                sum[j]+=nums[i];
                if(isPoss(nums,sum,lim,i+1))return true;
                sum[j]-=nums[i];
            }
            if(sum[j]==0)break;
        }
        return false;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {

        int x=accumulate(nums.begin(),nums.end(),0);
        if(x%k==0) {
            vector<int>sum(k,0);
            if(isPoss(nums,sum,x/k,0))return true;
        }
        return false;
    }
};