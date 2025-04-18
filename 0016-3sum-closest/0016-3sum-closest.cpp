class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans=INT_MAX/2, n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    int sum=nums[i]+nums[j]+nums[k];
                    if(abs(sum-target)< abs(ans-target)){
                        ans=sum;
                    }
                }
            }
        }
        return ans;
    }
};