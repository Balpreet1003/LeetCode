class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();
        unordered_map<long long ,long long>m;
        for(int i=0;i<n;i++){
            m[i-nums[i]]++;
        }
        for(auto &[i,j]:m){
            ans+=(long long)(((j-1)*j)/2);
        }
        
        return (((long long)n*(long long)(n-1))/2)-ans;
    }
};