class Solution {
public:
    int mySqrt(int x) {
        int ans=0;
        int i=1, j=x;
        while(i<=j){
            int mid=j-((j-i)/2);
            if(1LL*mid*mid<=x){
                ans=mid;
                i=mid+1;
            }
            else{
                j=mid-1;
            }
        }
        return ans;
    }
};