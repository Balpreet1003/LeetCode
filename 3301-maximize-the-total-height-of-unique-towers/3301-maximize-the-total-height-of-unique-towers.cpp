class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        sort(maximumHeight.rbegin(), maximumHeight.rend());
        long long val=maximumHeight[0], ans=0;
        for(int i=0;i<maximumHeight.size();i++)
        {
            if(val<1)
                return -1;
            val=min(val, 1LL*maximumHeight[i]);
            ans+=val;
            val--;
        }
        return ans;
    }
};