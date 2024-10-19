class Solution {
    char solve(int n,int k){
        if(n==1)return '0';

        int l=(1<<n)-1;
        int mid=l/2+1;
        if(k==mid)return '1';
        if(k<mid){
            return solve(n-1,k);
        }
        return solve(n-1,l-k+1)=='0'?'1':'0';
    }
public:
    char findKthBit(int n, int k) {
        return solve(n,k);
    }
};