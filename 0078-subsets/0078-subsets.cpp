class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        int a=pow(2,n);
        vector<vector<int>>ans;
        for(int k=0;k<a;k++){
            vector<int>b;
            int x=k;
            int j=0;
            while(x){
                if(x&1)b.push_back(nums[j]);
                j++;
                x=x>>1;
            }
            ans.push_back(b);
        }
        return ans;
    }
};