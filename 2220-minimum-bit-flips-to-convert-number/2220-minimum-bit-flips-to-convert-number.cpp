class Solution {
public:
    int minBitFlips(int start, int goal) {
        int x=start^goal, cnt=0;
        while(x){
            if(x&1)cnt++;
            x>>=1;
        }
        return cnt;
    }
};