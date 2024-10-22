class Solution {
private:
    bool isPossible(vector<int>&nums,int& m,int& k,int& mid){
        ios::sync_with_stdio(0);
        cin.tie(0);
        int count = 0;
        int bouquets = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] <= mid) {
                count++;
                if (count == k) {
                    bouquets++;
                    count = 0;
                }
            } else {
                count = 0;
            }
            
            if (bouquets >= m) {
                return true;
            }
        }
        
        return false;
    }
public:
    int minDays(vector<int>& nums, int m, int k) {
        int ans=-1;
        int s=0,e=*max_element(nums.begin(),nums.end());

        while(s<=e){
            int mid=s+(e-s)/2;
            if(isPossible(nums,m,k,mid)){
                e=mid-1;
                ans=mid;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
};