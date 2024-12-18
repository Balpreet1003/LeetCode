class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n=prices.size();
        vector<int>ans(n);
        ans[n-1]=prices[n-1];
        for(int i=n-2;i>=0;i--){
            int j=i+1;
            for(;j<n;j++){
                if(prices[j]<=prices[i])break;
            }
            if(j<n)ans[i]=prices[i]-prices[j];
            else ans[i]=prices[i];
        }
        return ans;
    }
};