class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_map<int,int>m;
        int ans=0;
        for(int i:nums){
            if(m.find(i)==m.end() && i>0){
                ans+=i;
                m[i]=1;
            }
        }
        if(ans==0){
            return *max_element(nums.begin(),nums.end());
        }
        return ans;
    }
};