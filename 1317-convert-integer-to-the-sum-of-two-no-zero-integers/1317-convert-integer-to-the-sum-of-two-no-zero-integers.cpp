class Solution {
    bool is_zero(int x){
        if(x<=0)return false;
        while(x){
            if(x%10==0)
                return false;
            x/=10;
        }
        return true;
    }
public:
    vector<int> getNoZeroIntegers(int n) {
        for(int i=1;i<=(n/2);i++){
            if(is_zero(i) && is_zero(n-i)){
                return {i, n-i};
            }
        }
        return {};
    }
};