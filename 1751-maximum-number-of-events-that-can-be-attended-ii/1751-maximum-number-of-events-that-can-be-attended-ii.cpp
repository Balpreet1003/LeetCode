class Solution {
    vector<vector<int>>dp;
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(),events.end());
        dp.resize(events.size()+1,vector<int>(k+1,0));
        for(int i=events.size()-1;i>=0;i--){
            for(int k1=1;k1<=k;k1++){
                int ans=dp[i+1][k1];
                int l=i+1,r=events.size();
                while(l<r){
                    int mid=l+(r-l)/2;
                    if(events[mid][0]>events[i][1]){
                        r=mid;
                    }
                    else{
                        l=mid+1;
                    }
                }
                ans=max(ans,events[i][2]+dp[l][k1-1]);
                dp[i][k1]=ans;
            }
        }
        return dp[0][k];
    }
};