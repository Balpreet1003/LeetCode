class Solution {
public:
    vector<int> missingRolls(vector<int>& nums, int mean, int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int sum=0,m=nums.size();
        for(int i:nums)sum+=i;

        if((mean*(n+m)>(sum+6*n)) || (mean*(n+m)-sum)<n)return {};

        int x=mean*(n+m)-sum;
        int i=x/n,j=0;
        vector<int>ans;
        while(j<n){
            while((x/(n-j))>i)i++;
            ans.push_back(i);
            x-=i;j++;
        }
        return ans;
    }
};