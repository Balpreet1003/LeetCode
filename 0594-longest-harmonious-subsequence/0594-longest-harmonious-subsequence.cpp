class Solution {
public:
    int findLHS(vector<int>& nums) {
        int ans=0;
        unordered_map<int,int>m;
        for(int i:nums){
            m[i]++;
        }
        for(auto &[x,y]:m){
            if(m.count(x + 1)){
                ans=max(ans,y+m[x+1]);
            }
        }
        return ans;
    }
};