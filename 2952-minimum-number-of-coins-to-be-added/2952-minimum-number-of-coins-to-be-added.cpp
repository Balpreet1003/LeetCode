class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        int sum=0, ans=0;
        sort(coins.begin(),coins.end());
        for(auto x:coins){
            while(x>sum+1){
                ans++;
                sum+=(sum+1);
                if(sum>=target){
                    return ans;
                }
            }
            sum+=x;
            if(sum>=target){
                return ans;
            }
        }
        while(sum<target){
            sum+=(sum+1);
            ans++;
        }
        return ans;
    }
};