class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n=prices.size(), t=k/2;
        vector<long long>pre_sum(n, 0), pre_sum1(n, 0);
        pre_sum[0]=prices[0]*strategy[0]*1LL;
        pre_sum1[0]=prices[0];
        for(int i=1;i<n;i++){
            pre_sum[i]=(pre_sum[i-1]+(prices[i]*strategy[i]*1LL));
            pre_sum1[i]=pre_sum1[i-1]+prices[i];
        }
        long long ans=pre_sum[n-1];
        for(int i=0;(i+k)<=n;i++){
            long long act_sum=pre_sum[n-1]-(pre_sum[i+k-1]-(i==0?0:pre_sum[i-1]));
            long long new_sum=pre_sum1[i+k-1]-pre_sum1[i+t-1];
            ans=max(ans, act_sum+new_sum);
        }
        return ans;
    }
};