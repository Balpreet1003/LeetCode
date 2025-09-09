class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if(nums.size()%k!=0)
            return false;
        map<int,int>m;
        for(int i:nums)
            m[i]++;
        for(auto [x,y]:m){
            while(y--){
                for(int i=x;i<x+k;i++){
                    if(m[i]==0)
                        return false;
                    m[i]--;
                }
            }
        }
        return true;
    }
};