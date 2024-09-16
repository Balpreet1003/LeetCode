class Solution {
public:
    int findMinDifference(vector<string>& b) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        vector<int>a;
        int n=b.size();
        for(int i=0;i<n;i++) a.push_back((stoi(b[i].substr(0, 2))*60) + (stoi(b[i].substr(3, 2))));

        sort(a.begin(),a.end());
        int ans=INT_MAX;
        for(int i=1;i<n;i++){
            ans=min(ans,a[i]-a[i-1]);
        }
        ans=min(ans,1440-a[n-1]+a[0]);
        return ans;
    }
};