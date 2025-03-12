class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int cntn=0,cntp=0;
        for(int i:nums){
            if(i<0)cntn++;
            else if(i>0)cntp++;
        }
        return max(cntn,cntp);
    }
};