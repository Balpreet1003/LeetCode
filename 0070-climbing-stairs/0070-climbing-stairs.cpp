class Solution {
public:
    int climbStairs(int n) {
        //intial condition
        int ptr1=1;
        int ptr2=1;
        int ans=ptr1;
        for(int i=2;i<=n;i++){
            ans=ptr1+ptr2;
            ptr2=ptr1;
            ptr1=ans;
        }
        return ans;
    }
};