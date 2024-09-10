class Solution {
public:
    int search(vector<int>& a, int t) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int i=0,j=a.size()-1;
        while(i<=j){
            int mid=(i+j)/2;
            if(a[mid]>t){
                j=mid-1;
            }
            else if(a[mid]==t){
                return mid;
            }
            else{
                i=mid+1;
            }
        }
        return -1;
    }
};