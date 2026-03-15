class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>>mp;
        for(int i=0;i<groupSizes.size();i++){
            mp[groupSizes[i]].push_back(i);
        }
        vector<vector<int>>ans;
        for(auto& [x, y] : mp){
            vector<int>arr;
            for(auto z:y){
                arr.push_back(z);
                if(arr.size()==x){
                    ans.push_back(arr);
                    arr={};
                }
            }
        }
        return ans;
    }
};