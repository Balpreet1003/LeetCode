class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        m[0]=1;
        int cnt=0,ans=0;
        for(int x:nums){
            if(x&1)cnt++;
            if(m.count(cnt-k)){
                ans+=m[cnt-k];
            }
            m[cnt]++;
        }
        return ans;
    }
};