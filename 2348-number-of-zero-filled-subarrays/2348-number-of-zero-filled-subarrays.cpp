#define ll long long
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        ll len=0, n=nums.size(), ans=0;
        for(auto x:nums){
            if(x==0){
                len++;
            }
            else{
                ans+=(len*(len+1)/2);
                len=0;
            }
        }
        ans+=(len*(len+1)/2);
        return ans;
    }
};