class Solution {
    bool is_poss(vector<int>& arr, int mid, int d){
        int cnt=1, sum=0;
        for(int i=0;i<arr.size();i++){
            if(sum+arr[i]<=mid){
                sum+=arr[i];
            }
            else{
                sum=arr[i];
                cnt++;
            }
        }
        return cnt<=d;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l=*max_element(weights.begin(), weights.end()), h=accumulate(weights.begin(), weights.end(), 0);
        int ans=-1;
        while(l<=h){
            int mid=h-((h-l)/2);
            if(is_poss(weights, mid, days)){
                ans=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};