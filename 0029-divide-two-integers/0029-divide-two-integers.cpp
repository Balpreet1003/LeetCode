class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor==1)return dividend;
        if(divisor==-1){
            if(dividend==INT_MIN)return INT_MAX;
            return -1*dividend;
        }

        bool neg1=divisor<0;
        bool neg2=dividend<0;

        long long x=abs((long long)dividend);
        long long y=abs((long long)divisor);

        int ans=0;
        while(x>=y){
            ans++;
            x-=y;
        }

        if(neg1)ans*=-1;
        if(neg2)ans*=-1;

        return ans;
    }
};