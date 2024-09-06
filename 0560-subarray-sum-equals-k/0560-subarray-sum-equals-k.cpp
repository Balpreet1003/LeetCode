class Solution {
public:
    int subarraySum(vector<int>& a, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        unordered_map<int,int>m;
        m[0]=1;
        int ans=0,sum=0;
        for(int i:a){
            sum+=i;
            if(m.find(sum-k)!=m.end())
                ans+=m[sum-k];
            m[sum]++;
        }
        return ans;
    }
};