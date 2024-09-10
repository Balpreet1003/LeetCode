class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int i=m+n-1;
        for(;i>=0;i--){
            if(nums1[i]!=0)break;
        }i++;
        for(int j=0;j<n;j++){
            nums1[i++]=nums2[j];
        }
        sort(nums1.begin(),nums1.end());
    }
};