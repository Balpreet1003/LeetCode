class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        int n=beans.size();
        sort(beans.begin(), beans.end());
        vector<long long>sum_arr(n, 0);
        sum_arr[n-1]=beans[n-1];
        for(int i=n-2;i>=0;i--)
        {
            sum_arr[i]=sum_arr[i+1]+1LL*beans[i];
        }
        long long sum=0, prev=-1, ans=LLONG_MAX;
        for(int i=0;i<n;i++)
        {
            if(prev==beans[i])
            {
                sum+=(1LL*beans[i]);
                continue;
            }
            ans=min(ans, sum+sum_arr[i]-(beans[i]*1LL*(n-i)));
            sum+=(1LL*beans[i]);
            prev=beans[i];
        }
        return ans;
    }
};