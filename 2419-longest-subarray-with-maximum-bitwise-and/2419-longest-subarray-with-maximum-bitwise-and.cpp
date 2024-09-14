class Solution {
public:
    int longestSubarray(vector<int>& a) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);

        int n=a.size(),ans=1,maxi=0,len=0;
        for(int i=0;i<n;i++)maxi=max(maxi,a[i]);

        for(int i:a){
            if(i==maxi)len++;
            else{
                ans=max(ans,len);
                len=0;
            }
        }
        ans=max(ans,len);
        return ans;
    }
};