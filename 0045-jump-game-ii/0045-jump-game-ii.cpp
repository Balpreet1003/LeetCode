class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int>cnt(n,INT_MAX);
        cnt[0]=0;
        for(int i=0;i<n;i++){
            if(cnt[i]!=INT_MAX){
                for(int j=i+1;j<=min(n-1,i+nums[i]);j++){
                    cnt[j]=min(cnt[j],cnt[i]+1);
                }
            }
        }
        return cnt[n-1];
    }
};