class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);

        int n=a.size();
        vector<vector<int>>ans;
        sort(a.begin(),a.end());
        for(int i=0;i<n;){
            int j=i+1,k=n-1;
            while(j<k){
                if(a[i]+a[j]+a[k]==0){
                    ans.push_back({a[i],a[j],a[k]});
                    j++;
                    while(j<k && a[j]==a[j-1])j++;
                    k--;
                    while(j<k && a[k]==a[k+1])k--;
                }
                else if(a[i]+a[j]+a[k]>0){
                    k--;
                }
                else{
                    j++;
                }
            }
            i++;
            while(i<n && a[i]==a[i-1])i++;
        }
        return ans;
    }
};