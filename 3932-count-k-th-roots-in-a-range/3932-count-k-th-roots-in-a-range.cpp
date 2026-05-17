class Solution {
    bool is_poss(int& mid, int& k, int& x)
    {
        if(mid==0)
            return true;
        int ans=1;
        for(int i=0;i<k;i++)
        {
            if(ans>(x/mid))
                return false;
            ans*=mid;
        }
        return ans<=x;
    }
    int kthroot(int x, int& k)
    {
        if(x<0)
            return -1;
        int low=0, high=1e9;
        int ans=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(is_poss(mid, k, x))
            {
                ans=mid;
                low=mid+1;
            }
            else
                high=mid-1;
        }
        return ans;
    }
public:
    int countKthRoots(int l, int r, int k) {
        int right=kthroot(r, k);
        int left=kthroot(l-1, k);
        return right-left;
    }
};