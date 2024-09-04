class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>m;
        for(int i:nums)m[i]++;
        for(auto i:m){
            if(i.second>(n/2))return i.first;
        }
        return 0;
    }
};