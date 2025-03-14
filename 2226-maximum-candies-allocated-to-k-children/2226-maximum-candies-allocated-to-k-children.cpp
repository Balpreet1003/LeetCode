#define ll long long
class Solution {
    bool isPossible(vector<int>&a,ll k,ll x){
        ll cnt=0;
        for(int i:a){
            cnt+=(i/x);
        }
        return cnt>=k;
    }
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int ans=0;
        ll i=1,j=0;
        for(int x:candies)j+=x;
        while(i<=j){
            ll mid=(i+j)/2;
            if(isPossible(candies,k,mid)){
                ans=mid;
                i=mid+1;
            }
            else{
                j=mid-1;
            }
        }
        return ans;
    }
};