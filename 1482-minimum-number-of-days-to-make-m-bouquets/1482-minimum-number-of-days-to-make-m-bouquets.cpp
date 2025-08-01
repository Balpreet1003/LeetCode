class Solution {
    bool is_possible(vector<int>&nums, int days, int m, int k){
        int cnt=0, x=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=days){
                x++;
            }
            else{
                cnt+=(x/k);
                x=0;
            }
        }
        cnt+=(x/k);
        return cnt>=m;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int i=1, j=*max_element(bloomDay.begin(), bloomDay.end()), ans=-1;
        while(i<=j){
            int mid=j-((j-i)/2);
            cout<<mid<<endl;
            if(is_possible(bloomDay,mid,m,k)){
                ans=mid;
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        return ans;
    }
};