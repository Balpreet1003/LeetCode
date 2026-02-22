class Solution {
public:
    int binaryGap(int n) {
        int ans=0, i=0, j=-1;
        while(n){
            if(n&1){
                if(j!=-1) 
                    ans=max(ans, i-j);
                j=i;
            }
            i++;
            n>>=1;
        }
        return ans;
    }
};