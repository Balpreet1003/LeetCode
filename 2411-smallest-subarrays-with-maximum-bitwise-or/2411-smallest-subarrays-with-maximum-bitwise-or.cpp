class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<int>a(32,0), ans(n,0);
        for(int i=n-1;i>=0;i--){
            int maxi=-1;
            for(int j=0;j<32;j++){
                if((nums[i]>>j)&1){
                    a[j]=i;
                }
                else{
                    maxi=max(maxi,a[j]);
                }
            }
            if(maxi<i){
                ans[i]=1;
            }
            else {
                ans[i]=maxi-i+1;
            }
        }
        return ans;
    }
};