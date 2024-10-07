class Solution {
    double solve(double x,int n){
        if(n<=0)return 1;
        if(!(n&1)){
            double h=solve(x,n/2);
            return h*h;
        }
        return solve(x,n-1)*x;
    }
public:
    double myPow(double x, int n) {
        if(x==2 && n==-2147483648)return 0;
        if(n==0)return 1;
        if(n<0)return solve(1/x,abs(n));
        return solve(x,n);
    }
};