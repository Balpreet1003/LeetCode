class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int>m;
        for(int i:nums)m[i]++;
        for(auto &[x,y]:m){
            if(y&1)return false;
        }
        return true;
    }
};