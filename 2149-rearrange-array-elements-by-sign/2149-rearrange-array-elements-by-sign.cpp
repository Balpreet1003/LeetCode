class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        int i=0;
        for(auto x:nums){
            if(x>0){
                ans[i]=x;
                i+=2;
            }
        }
        i=1;
        for(auto x:nums){
            if(x<0){
                ans[i]=x;
                i+=2;
            }
        }
        return ans;
    }
};