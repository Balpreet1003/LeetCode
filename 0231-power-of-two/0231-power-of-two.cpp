class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0){
            return false;
        }
        long long x=abs(n);
        int cnt=0;
        while(x){
            if(x&1){
                cnt++;
            }
            x>>=1;
        }
        return cnt==1;
    }
};