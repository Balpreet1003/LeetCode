class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>m;
        int maxi=0;
        for(int i:nums){
            m[i]++;
            maxi=max(maxi, m[i]);
        }
        int ans=0;
        for(auto &[x,y]:m){
            if(y==maxi)ans+=y;
        }
        return ans;
    }
};