class Solution {
public:
    int singleNonDuplicate(vector<int>& a) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int n = a.size();
        int i = 0, j = n - 1;
        
        while(i < j) {
            int mid = (i + j) / 2;
            if(mid&1) mid--;            
            if(a[mid] == a[mid+1])i = mid + 2;
            else j = mid;
        }
        return a[i];
    }
};