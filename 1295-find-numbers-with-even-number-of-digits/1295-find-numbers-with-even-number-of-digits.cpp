class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans=0;
        for(int i:nums){
            int x=i,cnt=0;
            while(x){
                cnt++;
                x/=10;
            }
            if(!(cnt&1))ans++;
        }
        return ans;
    }
};