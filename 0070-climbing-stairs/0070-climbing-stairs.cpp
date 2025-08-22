class Solution {
    vector<int>dp;
public:
    int climbStairs(int n) {
        int prev1=1, prev2=-1;
        for(int i=1;i<=n;i++){
            int curr=prev1;
            if(i>1)
                curr+=prev2;
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};