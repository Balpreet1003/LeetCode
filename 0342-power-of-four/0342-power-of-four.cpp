class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0){
            return false;
        }
        for(int i=0;i<32;i++){
            if((1<<i)==n){
                return !(i&1);
            }
        }
        return false;
    }
};