class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int k) {
        vector<int>ans;
        for(int i:nums){
            if(i<k)ans.push_back(i);
        }
        for(int i:nums){
            if(i==k)ans.push_back(i);
        }
        for(int i:nums){
            if(i>k)ans.push_back(i);
        }
        return ans;
    }
};