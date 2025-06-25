class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<bool>vis(n,false);
        vis[0]=true;
        for(int i=0;i<n-1;i++){
            if(vis[i]){
                if(i+nums[i]>=n-1){
                    return true;
                }
                for(int j=i+1;j<=min(n-1,i+nums[i]);j++){
                    vis[j]=true;
                }
            }
        }
        return vis[n-1];
    }
};