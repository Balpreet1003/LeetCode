class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        long long x;
        for(x=1;(1LL<<x)<k;x++);
        long long cnt=0;
        for(long long i=x-1;i>=0;i--){
            if(i>0){
                if(k>(1LL<<(i))){
                    if(operations[i]==1){
                        cnt++;
                    }
                    k-=(1LL<<i);
                }
            }
            else{
                if(k>1 && operations[i]==1){
                    cnt++;
                }
            }
        }
        cnt%=26;
        return (char)('a'+cnt);
    }
};