class Solution {
public:
    long long minEnd(int n, int x) {
        long long a=(long long)(n-1),ans=(long long)x,i=1;
        while(a){
            if(!(x&i)){
                ans|=(a&1)*i;
                a>>=1;
            }
            i<<=1;
        }
        return ans;

    }
};